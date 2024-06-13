// 程序说明:
// 本程序为解决交易员每日盘后清算盈亏数据使用。
// *******
// 
// 请交易员导出交易软件的持仓和成交数据后，将数据文件保存在本程序同一级文件夹中。
// 
// *******
// 更新日志：202-5-22  
//			 1.增加期货品种排序,map内部本身就是按序存储的（比如红黑树），这样方便实现快速查找。
//             在插入<key, value>键值对时，map就会自动按照key的大小顺序进行存储。因而作为key的类型必须能够进行大小运算的比较。
//			 2.核对平仓盈亏逐笔的统计方法；
//           3.github仓库：https://github.com/SamSmithchina/qingsuan.git
// 更新日志：202 - 3 - 21
// 
// 程序将会读取交易数据，自动计算全部品种、全部合约的持仓盈亏与成交逐笔盈亏。
// 考虑交易所的场内交易品种更新换代，未来的交易品种代码不确定，本程序有交易品种识别并匹配功能。每个合约代码自动区分并识别。
// 比如出现“M2305”识别为“M”品种，“M2305P3800”识别为“M”品种下“P3800”，
// 假如出现“MK305”，识别为“MK”品种， “MK305C5800”识别为“MK”品种"C5800"。
// 
// 本软件为非盈利性程序，代码开源，公开版权，遵守Apache Lience\BSD规范，仅供学习参考。
// 开发人员 Sam Smith ，
// email :sam-nuaa@nuaa.edu.cn





#pragma once
#ifndef HEAD_H
#define HEAD_H

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <direct.h>
#include <io.h>
#include <map>
#include <iomanip>
#include <codecvt>

using namespace std;



// 成交 类,共26个元素成员
class TRANSACTION
{
	char cInvestorID[20];				//投资者账号
	char cINvestorName[256];			//投资者
	char cFuturesConstracts[20];		//合约代码
	char cFuturesConstractsName[80];	//合约名称
	char cFuturesExchange[20];			//交易所
	int iTotal;							//合计量
	int iTurnover;						//净成交量
	int iBuyNumber;						//买数量
	float fBuyAveragePrice;				//买均价
	int iSellNumber;					//卖数量
	float fSellAveragePrice;			//卖均价

	int iBuyToOPen;						//买开
	float fBuyToOpenAveragePrice;		//买开均价
	int iSellToOPen;					//卖开
	float fSellToOpenAveragePrice;		//卖开均价
	int iBuyToClose;					//买平
	float fBuyToCloseAveragePrice;		//买平均价
	int iSellToClose;					//卖平
	float fSellToCloseAveragePrice;		//卖平均价

	//以下元素在表格可以为“--”，用0来表示，有数据的用数据表示
	float fServiceCharge;				//手续费
	float fAverageServiceCharge;		//手续费（平均）
	float fClosedProfits;				//平仓盈亏
	float fAverageClosedProfits;		//平仓盈亏（平均）
	float fTickByTickClosdProfits;		//平仓盈亏（逐笔）
	float fAverageTickByTickClosdProfits;//平仓盈亏（逐笔平均）

	char cUserID[20];						//下单用户

public:
	TRANSACTION(){};
	TRANSACTION(vector<string> vStr);
	void Display();							//显示函数

	char* GetFuturesConstractsName()		//获取品种星系
	{
		return cFuturesConstracts;
	}

	float GetTickByTickClosdProfits()		//获取平仓盈亏（逐笔）
	{
		return fTickByTickClosdProfits;
	}
	char* GetInvestorID()
	{
		return cInvestorID;
	}
	~TRANSACTION(){};
};

//显示函数
void TRANSACTION::Display()
{
	cout << "Display " << cInvestorID << "," << cINvestorName << "," << cFuturesConstracts << ","
		<< cFuturesConstractsName << "," << cFuturesExchange << ","
		<< iTotal << "," << iTurnover << "," << iBuyNumber << ","
		<< fBuyAveragePrice << "," << iSellNumber << "," << fSellAveragePrice << ","
		<< iBuyToOPen << "," << fBuyToOpenAveragePrice << ","
		<< iSellToOPen << "," << fSellToOpenAveragePrice << ","
		<< iBuyToClose << "," << fBuyToCloseAveragePrice << ","
		<< iSellToClose << "," << fSellToCloseAveragePrice << ","
		<< fServiceCharge << "," << fAverageServiceCharge << ","
		<< fClosedProfits << "," << fAverageClosedProfits << ","
		<< fTickByTickClosdProfits << "," << fAverageTickByTickClosdProfits << ","
		<< cUserID << endl;

}

TRANSACTION::TRANSACTION(vector<string> vStr)
{
	//vector<string>::iterator it = vStr.begin();
	int i = 0;

	strcpy_s(cInvestorID, vStr[i++].c_str());		//投资者账号
	strcpy_s(cINvestorName, vStr[i++].c_str());			//投资者
	strcpy_s(cFuturesConstracts, vStr[i++].c_str());		//合约代码

	strcpy_s(cFuturesConstractsName, vStr[i++].c_str());	//合约名称

	strcpy_s(cFuturesExchange, vStr[i++].c_str());		//交易所


	iTotal = stoi(vStr[i++].c_str());						//合计量

	iTurnover = stoi(vStr[i++].c_str());					//净成交量

	iBuyNumber = stoi(vStr[i++].c_str());					//买数量

	fBuyAveragePrice = stof(vStr[i++].c_str());			//买均价

	iSellNumber = stoi(vStr[i++].c_str());				//卖数量

	fSellAveragePrice = stof(vStr[i++].c_str());			//卖均价


	iBuyToOPen = stoi(vStr[i++].c_str());					//买开

	fBuyToOpenAveragePrice = stof(vStr[i++].c_str());		//买开均价

	iSellToOPen = stoi(vStr[i++].c_str());				//卖开

	fSellToOpenAveragePrice = stof(vStr[i++].c_str());	//卖开均价

	iBuyToClose = stoi(vStr[i++].c_str());				//买平

	fBuyToCloseAveragePrice = stof(vStr[i++].c_str());	//买平均价

	iSellToClose = stoi(vStr[i++].c_str());				//卖平

	fSellToCloseAveragePrice = stof(vStr[i].c_str()); //卖平均价

	i++;
	if (vStr[i] == "--")
		fServiceCharge = 0;
	else
		fServiceCharge = stof(vStr[i].c_str());			//手续费

	i++;
	if (vStr[i] == "--")
		fAverageServiceCharge = 0;
	else
		fAverageServiceCharge = stof(vStr[i].c_str());	//手续费（平均）

	i++;
	if (vStr[i] == "--")
		fClosedProfits = 0;
	else
		fClosedProfits = stof(vStr[i].c_str());		//平仓盈亏

	i++;
	if (vStr[i] == "--")
		fAverageClosedProfits = 0;
	else
		fAverageClosedProfits = stof(vStr[i].c_str());//平仓盈亏（平均）

	i++;
	if (vStr[i] == "--")
		fTickByTickClosdProfits = 0;
	else
		fTickByTickClosdProfits = stof(vStr[i].c_str());//平仓盈亏（逐笔）

	i++;
	if (vStr[i] == "--")
		fAverageTickByTickClosdProfits = 0;
	else
		fAverageTickByTickClosdProfits = stof(vStr[i].c_str());//平仓盈亏（逐笔平均）

	i++;
	strcpy_s(cUserID, vStr[i].c_str());					//下单用户
	//cout << "cUserID " << cUserID  << "   i = " << i<< endl;
}


// 持仓 类，共32个元素成员
class HOLDING
{
	char cInvestorID[20];				//投资者账号
	char cINvestorName[256];			//投资者
	char cFuturesExchange[20];			//交易所
	char cFuturesConstracts[20];		//合约代码
	char cFuturesConstractsName[80];	//合约名称
	bool  bBuyORSell;					//买卖方向，买 1，卖 0
	bool  bType;						//投资类型，投资 1，套利 0；
	int	iNUmberOFHeld;					//持仓数量
	float fLatestPrice;					//最新价
	float fAveragePriceOFHeld;			//持仓均价，两位有效小数
	float fAveragePriceOFOpenPositions;	//开仓均价，两位有效小数
	float fProfitsLossOFHOLding;		//持仓盈亏
	float fProFitsLossOFFloating;		//浮动盈亏
	float fPercentage;					//比例
	char cStopLossPrice[20];			//止损触发价,？表示默认"待设置"
	char cStopProfitPrice[20];			//止盈触发价，？表示 默认"待设置"
	char cStopNumber[20];				//出发手数，？表示“全部”或者某个数目
	int iYestardayNUmber;				//昨持仓
	int iTodayNumber;					//今持仓
	int iClosePositionNumber;			//可平量
	int iTodayClosePositionNumber;		//可平今量
	int iFrozenClosedPpositionnumber;	//平今冻结
	int iFrozenExercise = 0;			//行权冻结
	int iGiveUpFrozenExercise = 0;;		//放弃行权冻结
	int iComposedHOlding = 0;			//组合持仓
	float fOccupiedSecurityDeposit;		//占用保证金,百分数或者"--"
	float fpropotionOFFunds;			//资金占比
	bool bHoldingType;					//持仓类型，义务仓 1， 权力仓 0；
	float OptionMarketValue;			//期权市值
	char* cCurrency = NULL;				//币种，默认无币种
	float fExchangeRate = 1;			//汇率,默认1
	int iTASHolding = 0;				//TAS持仓，默认0

public:
	HOLDING()
	{
		cStopLossPrice[20] = '?';		//止损触发价,？表示默认"待设置"
		cStopProfitPrice[20] = '?';		//止盈触发价，？表示 默认"待设置"
		cStopNumber[20] = '?';			//出发手数，？表示“全部”,或者根据指令修改某个数目
	}
	HOLDING(vector<string> vStr);
	~HOLDING(){};
	float GetProFitsFloating()			//获取浮动盈亏
	{
		return fProFitsLossOFFloating;
	}

	char* GetFuturesConstracts()		//获取合约代码
	{
		return cFuturesConstracts;
	}
	char * GetInvestorID()
	{
		return cInvestorID;
	}
};

HOLDING::HOLDING(vector<string> vStr)
{
	vector<string>::iterator it = vStr.begin();
	//char cInvestorID[20];					//投资者账号
	strcpy_s(cInvestorID, it->c_str());
	it++;
	//char cINvestorName[256];				//投资者
	strcpy_s(cINvestorName, it->c_str());
	it++;
	//char cFuturesExchange[20];			//交易所
	strcpy_s(cFuturesExchange, it->c_str());
	it++;
	//char cFuturesConstracts[20];			//合约代码
	strcpy_s(cFuturesConstracts, it->c_str());
	it++;

	//char cFuturesConstractsName[80];		//合约名称
	strcpy_s(cFuturesConstractsName, it->c_str());
	it++;

	//bool  bBuyORSell;						//买卖方向，买 1，卖 0
	if (*it == "1")
	{
		bBuyORSell = true;
	}
	else
	{
		bBuyORSell = false;
	}
	it++;

	//bool  bType;							//投资类型，投资 1，套利 0；
	if (*it == "1")
	{
		bType = true;
	}
	else
	{
		bType = false;
	}
	it++;

	//int	iNUmberOFHeld;					//持仓数量
	iNUmberOFHeld = stoi(it->c_str());
	it++;
	//float fLatestPrice;					//最新价
	fLatestPrice = stof(it->c_str());
	it++;

	//float fAveragePriceOFHeld;			//持仓均价，两位有效小数
	fAveragePriceOFHeld = stof(it->c_str());
	it++;
	//float fAveragePriceOFOpenPositions;	//开仓均价，两位有效小数
	fAveragePriceOFOpenPositions = stof(it->c_str());
	it++;
	//float fProfitsLossOFHOLding;			//持仓盈亏
	fProfitsLossOFHOLding = stof(it->c_str());
	it++;
	//float fProFitsLossOFFloating;			//浮动盈亏
	if (*it == "--")
		fProFitsLossOFFloating = 0;
	else
		fProFitsLossOFFloating = stof(it->c_str());
	it++;
	//float fPercentage;					//比例
	fPercentage = stof(it->c_str());
	it++;
	//char cStopLossPrice[20];					//止损触发价,？表示默认"待设置"
	strcpy_s(cStopLossPrice, it->c_str());
	it++;
	//char cStopProfitPrice[20];				//止盈触发价，？表示 默认"待设置"
	strcpy_s(cStopProfitPrice, it->c_str());
	it++;
	//char cStopNumber[20];						//出发手数，？表示“全部”或者某个数目
	strcpy_s(cStopNumber, it->c_str());
	it++;

	//int iYestardayNUmber;						//昨持仓
	iYestardayNUmber = stoi(it->c_str());
	it++;
	//int iTodayNumber;							//今持仓
	iTodayNumber = stoi(it->c_str());
	it++;
	//int iClosePositionNumber;					//可平量
	iClosePositionNumber = stoi(it->c_str());
	it++;
	//int iTodayClosePositionNumber;			//可平今量
	iTodayClosePositionNumber = stoi(it->c_str());
	it++;
	//int iFrozenClosedPpositionnumber;			//平今冻结
	iFrozenClosedPpositionnumber = stoi(it->c_str());
	it++;

	iFrozenExercise = 0;						//行权冻结
	iGiveUpFrozenExercise = 0;;				//放弃行权冻结
	iComposedHOlding = 0;						//组合持仓

	//float fOccupiedSecurityDeposit;			//占用保证金,百分数或者"--"
	fOccupiedSecurityDeposit = stof(it->c_str());
	it++;
	//float fpropotionOFFunds;					//资金占比
	fpropotionOFFunds = stof(it->c_str());
	it++;
	//bool bHoldingType;						//持仓类型，义务仓 1， 权力仓 0；
	if (*it == "1")
		bHoldingType = true;
	else
		bHoldingType = false;
	it++;

	//float OptionMarketValue;					//期权市值
	OptionMarketValue = stof(it->c_str());
	it++;

	char* cCurrency = NULL;						//币种，默认无币种
	float fExchangeRate = 1;					//汇率,默认1
	int iTASHolding = 0;						//TAS持仓，默认0

}

//输入：
//获取string类型年月日时间
//输出：string年月日，比如“2023_03_21”
string GetTime()
{
	//获取今天日期；
	time_t timeNow;
	string strTime;
	time(&timeNow);//获取1970年1月1日0点0分0秒到现在经过的秒数
	tm p;
	int i = 0;
	localtime_s(&p, &timeNow);

	//将秒数转换为本地时间,年从1900算起,需要+1900,月为0-11,所以月要+1
	i = p.tm_year + 1900;
	strTime = to_string(i);
	strTime.append("_");
	i = p.tm_mon + 1;
	if (i < 10)
		strTime.append("0");
	strTime.append(to_string(i));
	strTime.append("_");
	i = p.tm_mday;
	if (i < 10)
		strTime.append("0");
	strTime.append(to_string(i));
	//cout << "当前时间 ： " << strTime << endl;
	return strTime;
}




// 输入：待查找文件是“成交汇总”或者“实时持仓”
// 搜索文件夹下的成交汇总CSV文件或者实时持仓CSV文件
// 输出：一个记录成交汇总或者持仓CSV文件名CSV文件名的string；
vector<string>  SearchCSVFile(string strFile)
{
	int iFlag = -1;
	char cwd[256];
	_getcwd(cwd, 256);
	string strTempDir = cwd;			//执行程序当前路径；
	strTempDir.append("\\*");

	const string strFileType = ".csv";	//指定文件类型
	long   hFile = 0;					// 文件句柄
	vector<string> vecFiles;			//存储符合的文件；
	struct _finddata_t fileinfo;		//文件信息
	string strTime;
	string strTempFile;
	string strPath;

	hFile = _findfirst(strTempDir.c_str(), &fileinfo);
	if (hFile != -1) //存在文件
	{
		do {
			strTempFile = fileinfo.name;
			if (strTempFile.find(strFile) != string::npos)
			{
				strTime = GetTime();							//文件名字格式如“实时持仓_2023_03_21-15_28_49.csv”
				if (strTempFile.find(strTime) != string::npos  //按关键字和csv格式寻找文件
					&& strTempFile.find(strFileType) != string::npos)
				{
					strPath = cwd;
					vecFiles.push_back(strPath.append("\\").append(strTempFile));
				}
			}

		} while (_findnext(hFile, &fileinfo) == 0);  //寻找下一个，成功返回0，否则-1
		_findclose(hFile);		//close
	}

	return vecFiles;
}


// 输入： 持仓类
// 持仓文件读取,读取无限易的实时持仓***.csv格式文件，存储在持仓类中
// 输出： 0， 正常完成读取；-1，读取过程异常
//int HlodingCSVFileRead(string strFileName)
int HlodingCSVFileRead(vector<HOLDING> &Holding, string strFile)
{
	ifstream fileCSV;
	fileCSV.open(strFile, ios::in);
	string strFileTemp = strFile.substr(strFile.rfind('\\') + 1, strFile.npos);
	if (fileCSV.is_open() == false)
	{
		cout << "读取 " << strFileTemp << "   失败。" << endl
			<< "请保证其他程序不在使用该文件，并关闭本程序再试." << endl;
		fileCSV.close();
		return -1; //结束异常程序
	}

	string strLine;
	if (!getline(fileCSV, strLine))			 //读取第一行
		return -1;							//空文件或者无交易记录文件，返回-1

	HOLDING HoldingTemp;
	vector<string> vWord;
	string strWord;
	string strTemp;
	//解析成交订单信息
	while (getline(fileCSV, strLine))		//逐行读取
	{
		vWord = {};							//初始化
		stringstream strTemp(strLine);		//字符流
		while (getline(strTemp, strWord, ','))		//以“, ”号字符分割
		{
			vWord.push_back(strWord);
		}
		//初始化
		HoldingTemp = HOLDING(vWord);
		//获取一行记录
		Holding.push_back(HoldingTemp);
	}

	cout << strFileTemp << " 文件读取完毕！ " << endl;
	fileCSV.close();
	return 0;

}

//输入 ：  map<pair<string, string>, pair<float, string>> mapHolding,
//功能 ：  计算每个投资者账户下的全部持仓浮动盈亏，在mapHolding中插入<投资者、“全部”、flaot浮动盈亏，string 文件名字>
//输出 ：  mapHolding
map<pair<string, string>, pair<float, string>> TotalMapHoling(map<pair<string, string>, pair<float, string>> mapHolding)
{
	map<pair<string, string>, pair<float, string>>::iterator itMap;
	map<pair<string, string>, pair<float, string>>::iterator itMapNext;
	float fTotal = 0;
	float fTemp = 0;
	itMap = mapHolding.begin();
	itMapNext = itMap;

	for (itMap; itMap != mapHolding.end(); itMap++)
	{
		fTemp = itMap->second.first;
		fTotal += fTemp;
		//获取下一个指针
		itMapNext = ++itMap;
		itMap--;
		if (itMapNext == mapHolding.end())
		{
			mapHolding.insert(make_pair(make_pair(itMap->first.first, "全部"), make_pair(fTotal, itMap->second.second)));
		}
		else if (itMapNext != mapHolding.end())
		{
			if (itMapNext->first.first != itMap->first.first)
				mapHolding.insert(make_pair(make_pair(itMap->first.first, "全部"), make_pair(fTotal, itMap->second.second)));
		}
	}

	return mapHolding;
}

//输入： map<pair<string, string>, pair<float, string>> mapTranscation,
//		 map<pair<string, string>, pair<float, string>> mapHolding,
//功能： 合并两个map,
//输出： 合并后的map,按照<<投资者，期货代码名称>，<平仓盈亏，持仓盈亏>>，按<投资者,期货代码>分类正序排序，
map<pair< string, string >, pair< float, float >> MergeMap(
	map<pair<string, string>, pair<float, string>> mapTranscation,
	map<pair<string, string>, pair<float, string>> mapHolding)
{
	//记录最终结果的map
	map<pair<string, string>, pair<float, float>> mapResult;
	//迭代器
	map<pair<string, string>, pair<float, string>>::iterator mapTransIt;
	map<pair<string, string>, pair<float, string>>::iterator mapHoldingIt;

	//处理持仓盈亏总量
	mapHolding = TotalMapHoling(mapHolding);

	//先处理mapTranscation
	for (mapTransIt = mapTranscation.begin(); mapTransIt != mapTranscation.end(); mapTransIt++)
	{
		//查找对用投资者账户特定品种代码的浮动盈亏
		mapHoldingIt = mapHolding.find(mapTransIt->first);
		//有投资者账户特定品种代码下的浮动盈亏和平仓盈亏
		if (mapHoldingIt != mapHolding.end())
		{
			//存储结果
			mapResult.insert(make_pair(mapTransIt->first, make_pair(mapTransIt->second.first, mapHoldingIt->second.first)));
		}
		// 持仓浮动盈亏 = 0，只有平仓盈亏
		else
		{
			//存储结果
			mapResult.insert(make_pair(mapTransIt->first, make_pair(mapTransIt->second.first, 0)));
		}

	}
	//处理完成平仓盈亏，处理剩下的持仓浮动盈亏
	for (mapHoldingIt = mapHolding.begin(); mapHoldingIt != mapHolding.end(); mapHoldingIt++)
	{
		//查找对用投资者账户特定品种代码的平仓
		mapTransIt = mapTranscation.find(mapHoldingIt->first);
		//有投资者账户特定品种代码下的浮动盈亏和平仓盈亏,在前面已经处理完成；
		if (mapTransIt != mapTranscation.end())
			continue;	//直接跳过不用处理
		else
		{
			//存储结果
			// 只有持仓浮动盈亏，平仓盈亏= 0
			mapResult.insert(make_pair(mapHoldingIt->first, make_pair(0, mapHoldingIt->second.first)));
		}
	}


	return mapResult;
}

//输入：存储读文件结果的数组mapArr;<string 账户名，string 期货合约代码 ， float 平仓盈亏逐笔统计，float 浮动盈亏>
//      源文件 strFile 计算结果输出文件strResultFile；
//功能：计算结果写入指定文件 平仓盈亏逐笔.txt
//输出：0 正常写，-1 异常
int ElasticityTotalResaultToTXT(
	map<pair< string, string >, pair< float, float >> mergeMap,
	string strResultFile)
{
	ofstream of;
	of.open(strResultFile, ofstream::app);
	if (!of.is_open())
	{
		cout << "打开" << strResultFile << "文件失败！\n 请关闭其他正在使用该文件的程序" << endl;
		return -1;
	}

	//合并

	//bool bFlag = false;
	const string str1 = "------------------------------------------------------";
	const string str2 = "                                                      ";
	const string str3 = "合约代码";
	const string str4 = "平仓盈亏逐笔";
	const string str5 = "持仓盈亏";
	string str6 = "";
	//期货品种按英文字母A - Z顺序排序,
	map<pair<string, string>, pair<float, float>>::iterator mapIt = mergeMap.begin();
	string strInvestorID = "";
	string strFrontInvestorID = "";
	string strConstractsName = "";
	float fProFitsLossOFFloating = 0;
	float ffTickByTickClosdProfits;


	while (mapIt != mergeMap.end())
	{
		//文件名

		//投资者账户
		strInvestorID = mapIt->first.first;
		if (strFrontInvestorID != strInvestorID)
		{
			/*
			of << endl << strFile << "  统计如下：" << endl;
			cout << endl << strFile << "  统计如下：" << endl;
			*/
			//固定输出表格样式
			of << endl << "账号   " << strInvestorID << endl
				<< "|" << str1 << "|" << endl
				<< "|  " << left << setw(10) << str3
				<< "|  " << left << setw(18) << str4
				<< "|  " << left << setw(18) << str5 << "|" << endl
				<< "|" << str1 << "|" << endl;
			cout << endl << "账号   " << strInvestorID << endl
				<< "|" << str1 << "|" << endl
				<< "|  " << left << setw(10) << str3
				<< "|  " << left << setw(18) << str4
				<< "|  " << left << setw(18) << str5 << "|" << endl
				<< "|" << str1 << "|" << endl;
		}

		//期货合约代码
		strConstractsName = mapIt->first.second;
		//固定输出表格样式
		if (strConstractsName.compare("全部") >= 0)
		{
			//bFlag = true;
			of << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;

			cout << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;
		}

		// 统计两种盈亏
		ffTickByTickClosdProfits = mapIt->second.first;
		fProFitsLossOFFloating = mapIt->second.second;

		// 输出期货品种名称
		if (strConstractsName.size() > 3)
			of << "|  " << left << setw(11) << strConstractsName;
		else
			of << "|  " << left << setw(10) << strConstractsName;
		cout << "|  " << left << setw(10) << strConstractsName;

		//输出平仓盈亏逐笔和浮动盈亏
		if (ffTickByTickClosdProfits == 0)
		{
			of << "|  " << left << setw(18) << str6 << "|  ";
			cout << "|  " << left << setw(18) << str6 << "|  ";
		}
		else
		{

			of << "|  " << left << setw(18) << ffTickByTickClosdProfits << "|  ";
			cout << "|  " << left << setw(18) << ffTickByTickClosdProfits << "|  ";
		}
		if (fProFitsLossOFFloating == 0)
		{
			of << left << setw(18) << str6 << "|" << endl
				<< "|" << str2 << "|" << endl;
			cout << left << setw(18) << str6 << "|" << endl
				<< "|" << str2 << "|" << endl;
		}
		else
		{
			of << left << setw(18) << fProFitsLossOFFloating << "|" << endl
				<< "|" << str2 << "|" << endl;
			cout << left << setw(18) << fProFitsLossOFFloating << "|" << endl
				<< "|" << str2 << "|" << endl;
		}

		strFrontInvestorID = strInvestorID;
		mapIt++;

	}

	of << "|" << str1 << "|" << endl << endl << endl;
	cout << "|" << str1 << "|" << endl << endl << endl
		<< "统计结果保存在 : " << strResultFile << endl << endl << endl;

	of.close();
	return 0;
}

//输入：存储读文件结果的数组mapArr;<string 账户名，string 期货合约代码 ， float 平仓盈亏逐笔统计>
//      源文件 strFile 计算结果输出文件strResultFile；
//功能：计算结果写入指定文件 平仓盈亏逐笔.txt
//输出：0 正常写，-1 异常
int ElasticityResaultToTXT(map<pair<string, string>, pair<float, string>> mapArr, string strResultFile)
{
	ofstream of;
	of.open(strResultFile, ofstream::app);
	if (!of.is_open())
	{
		cout << "打开" << strResultFile << "文件失败！\n 请关闭其他正在使用该文件的程序" << endl;
		return -1;
	}
	if (mapArr.size() == 0)
	{
		return 0;
	}

	//bool bFlag = false;
	const string str1 = "---------------------------------";
	const string str2 = "                                 ";
	//期货品种按英文字母A - Z顺序排序,
	map<pair<string, string>, pair<float, string>>::iterator mapIt = mapArr.begin();
	string strInvestorID = "";
	string strFrontInvestorID = "";
	string strConstractsName = "";
	float fProfits = 0;
	string strFile = "";


	while (mapIt != mapArr.end())
	{
		////文件名
		strFile = mapIt->second.second;


		strInvestorID = mapIt->first.first;
		if (strFrontInvestorID != strInvestorID)
		{
			of << endl << strFile << "  统计如下：" << endl;
			cout << endl << strFile << "  统计如下：" << endl;

			of << endl << "账号   " << strInvestorID << endl
				<< "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;
			cout << endl << "账号   " << strInvestorID << endl
				<< "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;
		}

		strConstractsName = mapIt->first.second;
		//固定输出表格样式
		if (strConstractsName.compare("全部") >= 0)
		{
			//bFlag = true;
			of << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;

			cout << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;
		}

		fProfits = mapIt->second.first;
		strFile = mapIt->second.second;
		// 输出期货品种名称
		if (strConstractsName.size() > 3)
			of << "|  " << left << setw(11) << strConstractsName;
		else
			of << "|  " << left << setw(10) << strConstractsName;
		//输出浮动盈亏
		of << "|  " << left << setw(18) << fProfits << "|" << endl
			<< "|" << str2 << "|" << endl;

		cout << "|  " << left << setw(10) << strConstractsName
			<< "|  " << left << setw(18) << fProfits << "|" << endl
			<< "|" << str2 << "|" << endl;

		strFrontInvestorID = strInvestorID;
		mapIt++;

	}

	of << "|" << str1 << "|" << endl << endl << endl;
	cout << "|" << str1 << "|" << endl << endl << endl;

	of.close();
	return 0;
}

//输入：map<string,float> 结构的<品种,逐笔盈亏>， 
//      账户唯一账号 strInvestorID,源文件 strFile 计算结果输出文件strResultFile；
//功能：计算结果写入指定文件
//输出：0 正常写，-1 异常
int ResaultToTXT(map<string, float> mapArr, string strInvestorID, string strFile, string strResultFile)
{
	ofstream of;
	of.open(strResultFile, ofstream::app);
	if (!of.is_open())
	{
		cout << "打开" << strResultFile << "文件失败！\n 请关闭其他正在使用该文件的程序" << endl;
		return -1;
	}
	if (mapArr.size() == 0)
	{
		return 0;
	}

	bool bFlag = false;
	const string str1 = "---------------------------------";
	const string str2 = "                                 ";

	//期货品种按英文字母A - Z顺序排序
	map<string, float>::iterator mapIt = mapArr.begin();
	string strTemp = strFile.substr(strFile.rfind('\\') + 1, strFile.npos);		//文件名
	of << strTemp << "  统计如下：" << endl;
	of << endl << "账号   " << strInvestorID << endl
		<< "|" << str1 << "|" << endl
		<< "|" << str2 << "|" << endl;
	cout << endl << "账号   " << strInvestorID << endl
		<< "|" << str1 << "|" << endl
		<< "|" << str2 << "|" << endl;

	while (mapIt != mapArr.end())
	{
		//固定输出表格样式
		if (mapIt->first.compare("全部") >= 0 && bFlag == false)
		{
			bFlag = true;
			of << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;

			cout << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;
		}

		if (mapIt->first.size() > 3)
			of << "|  " << left << setw(11) << mapIt->first;
		else
			of << "|  " << left << setw(10) << mapIt->first;

		of << "|  " << left << setw(18) << mapIt->second << "|" << endl
			<< "|" << str2 << "|" << endl;
		cout << "|  " << left << setw(10) << mapIt->first
			<< "|  " << left << setw(18) << mapIt->second << "|" << endl
			<< "|" << str2 << "|" << endl;

		mapIt++;
	}

	of << "|" << str1 << "|" << endl << endl << endl;
	cout << "|" << str1 << "|" << endl << endl << endl;

	of.close();
	return 0;
}

//输入：持仓汇总类HOLDING 的vector数组，源文件名 strFile
//功能：期货品种编码用小写字母表示， m 大豆，ru 橡胶
//		统计每个合约的平仓盈亏（逐笔）,结果写到“持仓浮动盈亏.txt”。
//输出：0表示执行正常，-1 表示执行异常
int HoldingProfitsFloating(vector<HOLDING> vHolding, string strFile)
{
	map<string, float> mapArr;			//数据集mapArr：统计品种和平仓盈亏逐笔
	map<string, float>::iterator mapIt;
	vector<HOLDING>::iterator holdIt = vHolding.begin();
	char* cConstraction = NULL;
	string str;
	float fProfits = 0;
	float fTotal = 0;
	int i = 0;
	int iFuture;
	bool bOption;
	bool bNumber;
	string strInvestorID = holdIt->GetInvestorID();

	for (; holdIt != vHolding.end(); holdIt++) //逐笔统计成交订单
	{
		iFuture = 0;		//不是期货
		bOption = false;	//不是期权
		bNumber = false;	//没有合约时间

		//取得取货合约
		cConstraction = holdIt->GetFuturesConstracts();

		//取得期货平仓逐笔盈亏
		fProfits = holdIt->GetProFitsFloating();
		fTotal += fProfits;

		for (i = 0; i <(int)strlen(cConstraction); i++)
		{
			//if (cConstraction[i] >= 97 && cConstraction[i] <= 122			//97 是小写a ，122是小写z
			//	|| cConstraction[i] >= 65 && cConstraction[i] <= 90)		//65是大写A ， 90是大写Z
			if (cConstraction[i]>57 || cConstraction[i] < 48)				//48是数字0, 57是数字9
			{
				if (bOption == false && bNumber == false)					//是期货还是期权
				{

					iFuture++;				//先处理期货合约代码
				}
				if (bNumber == true && bOption == false)
				{
					bOption = true;			//是期权合约
					break;
				}
			}
			else							//遇到数字
			{
				bNumber = true;				//期权才会在期货合约后加P、C表示人后认沽
			}
		}

		//表明期货和期权的合约代码
		str.clear();
		//if (bOption == true)
		//{
		//	str.append(cConstraction, iFuture);
		//	str += " 期权";	//注明“期权”字样，以示区分

		//}
		//else
		str.append(cConstraction, iFuture);

		//先查找有没有这种品种的交易记录；
		mapIt = mapArr.find(str);
		if (mapIt != mapArr.end())
		{
			//如果已经有这个品种，只需要在这个品种的逐笔盈亏上加减后续盈亏
			mapIt->second = mapIt->second + fProfits;
		}
		else
		{
			//如果没有这个品种，新开一个品种和盈亏
			mapArr.insert(pair<string, float>(str, fProfits));
		}
	}
	mapArr.insert(pair<string, float>("全部", fTotal));
	return (ResaultToTXT(mapArr, strInvestorID, strFile, "持仓浮动盈亏.txt"));
}


//输入
//成交汇总文件读取
//输出： 0， 正常完成读取；-1，读取过程异常
int TransactionCSVFileRead(vector<TRANSACTION>& Trans, string strFile)
{
	ifstream fileCSV;
	fileCSV.open(strFile, ios::in);
	string strFileTemp = strFile.substr(strFile.rfind('\\') + 1, strFile.npos);
	if (fileCSV.is_open() == false)
	{
		cout << "读取 " << strFileTemp << "   失败。" << endl
			<< "请保证其他程序不在使用该文件，并关闭本程序再试." << endl;
		fileCSV.close();
		return -1; //结束异常程序
	}

	string strLine;
	if (!getline(fileCSV, strLine))			 //读取第一行
		return -1;							//空文件或者无交易记录文件，返回-1

	TRANSACTION TransTemp;
	vector<string> vWord;
	string strWord;
	string strTemp;
	//解析成交订单信息
	while (getline(fileCSV, strLine))		//逐行读取
	{
		vWord = {};							//初始化
		stringstream strTemp(strLine);		//字符流
		while (getline(strTemp, strWord, ','))		//以“, ”号字符分割
		{
			vWord.push_back(strWord);
		}
		//初始化
		TransTemp = TRANSACTION(vWord);
		//获取一行记录
		Trans.push_back(TransTemp);
	}

	cout << strFileTemp << " 文件读取完毕！ " << endl;
	fileCSV.close();
	return 0;

}



//输入：成交汇总类TRANSCATION 的vector数组，成交汇总文件名strFile
//功能：期货品种编码用小写字母表示， m 大豆，ru 橡胶
//		统计每个合约的平仓盈亏（逐笔）,结果写到“平仓盈亏逐笔.txt”。
//输出：0表示执行正常，-1 表示执行异常
int TickByTickTransactionProfits(vector<TRANSACTION> vTrans, string strFile)
{
	map<string, float> mapArr;			//数据集mapArr：统计品种和平仓盈亏逐笔
	map<string, float>::iterator mapIt;
	vector<TRANSACTION>::iterator transIt = vTrans.begin();
	char* cConstraction = NULL;
	string str;
	float fProfits = 0;
	int i = 0;
	int iFuture;
	bool bOption;
	bool bNumber;
	string strInvestorID = transIt->GetInvestorID();

	for (; transIt != vTrans.end(); transIt++) //逐笔统计成交订单
	{
		iFuture = 0;		//不是期货
		bOption = false;	//不是期权
		bNumber = false;	//没有合约时间

		//取得取货合约
		cConstraction = transIt->GetFuturesConstractsName();

		//取得期货平仓逐笔盈亏
		fProfits = transIt->GetTickByTickClosdProfits();

		for (i = 0; cConstraction[i] != '\0'; i++)
		{
			//将期货合约统一为大写字母表示
			if (cConstraction[i] >= 97 && cConstraction[i] <= 122)			//97 是小写a ，122是小写z
			{
				//	|| cConstraction[i] >= 65 && cConstraction[i] <= 90)	//65是大写A ， 90是大写Z
				cConstraction[i] -= 32;										//小写字母转大写字母，
			}
			if (cConstraction[i] > 57 || cConstraction[i] < 48)				//48是数字0, 57是数字9
			{
				if (bOption == false && bNumber == false)					//是期货还是期权
				{

					iFuture++;				//先处理期货合约代码
				}
				if (bNumber == true && bOption == false)
				{
					bOption = true;			//是期权合约
					break;
				}
			}
			else							//遇到数字
			{
				bNumber = true;				//期权才会在期货合约后加P、C表示人后认沽
			}
		}

		//记录下单用户账户


		//表明期货和期权的合约代码
		str.clear();
		//if (bOption == true)
		//{
		//	str.append(cConstraction, iFuture);
		//	str += " 期权";	//注明“期权”字样，以示区分
		//}
		//else
		str.append(cConstraction, iFuture);

		//先查找有没有这种品种的交易记录；
		mapIt = mapArr.find(str);
		if (mapIt != mapArr.end())
		{
			//如果已经有这个品种，只需要在这个品种的逐笔盈亏上加减后续盈亏
			mapIt->second = mapIt->second + fProfits;
		}
		else
		{
			//如果没有这个品种，新开一个品种和盈亏
			mapArr.insert(pair<string, float>(str, fProfits));
		}
	}

	//	map<string ,string ,float> mapArray
	return (ResaultToTXT(mapArr, strInvestorID, strFile, "平仓盈亏逐笔.txt"));
}


//输入： string strFileName文件名,
//功能： 读取strFileName文件，自适应strFileName中数据的分布顺序、数据列数；
//输出： 返回存储读文件结果的数组mapArr;<string 账户名，string 期货合约代码 ， float 平仓盈亏逐笔统计,string文件名>
map<pair<string, string>, pair<float, string>> ElasticityHoldingCSVFileRead(
	map<pair<string, string>, pair<float, string>>& mapArr,
	string strFileName)
{
	ifstream fileCSV;
	fileCSV.open(strFileName, ios::in);
	string strFileTemp = strFileName.substr(strFileName.rfind('\\') + 1, strFileName.npos);
	if (fileCSV.is_open() == false)
	{
		cout << "读取 " << strFileTemp << "   失败。" << endl
			<< "请保证其他程序不在使用该文件，并关闭本程序再试." << endl;
		fileCSV.close();
		return mapArr;
	}

	string strLine;
	if (!getline(fileCSV, strLine))			 //读取第一行
		return mapArr;						//空文件或者无交易记录文件，结束读取

	//解析第一行
	int iInvestorID = 0;
	int iFuturesConstracts = 0;
	int iProFitsLossOFFloating = 0;
	int i = 0;
	vector<string> vWord;
	string strWord;							//分割后的子串
	stringstream strStreamTemp(strLine);		//字符流
	i = 0;
	while (getline(strStreamTemp, strWord, ','))//以“, ”号字符分割
	{
		if (strWord.compare("投资者账号") == 0)
		{
			iInvestorID = i;					//期货账户所在列数
		}
		if (strWord.compare("合约代码") == 0)
		{
			iFuturesConstracts = i;				//合约代码所在列数
		}
		if (strWord.compare("浮动盈亏") == 0)
		{
			iProFitsLossOFFloating = i;		//计算CSV "平仓盈亏(逐笔)"在的列数,
		}
		i++;
	}

	string strInvestorID;					//账户名
	string strFrontInverstorID;				//用于记录表格中“全部”一行的账户名
	string strConsTractName;				//期货合约代码
	float fProFitsLossOFFloating;			//浮动盈亏
	float fTotalProFitsLossOFFloating = 0;
	float fTemp = 0;
	vector<string>::iterator it;
	map<pair<string, string>, pair<float, string>>::iterator mapIt;
	pair<string, string> pairTemp;

	//解析成交订单信息的剩余行
	while (getline(fileCSV, strLine))		//逐行读取
	{
		vWord = {};							//初始化
		fProFitsLossOFFloating = 0;
		fTotalProFitsLossOFFloating = 0;
		strStreamTemp = stringstream(strLine);		//字符流
		while (getline(strStreamTemp, strWord, ','))		//以“, ”号字符分割
		{
			vWord.push_back(strWord);
		}

		//获取期货账号
		it = vWord.begin() + iInvestorID;
		strInvestorID = *it;


		//获取期货品种合约代码
		it = vWord.begin() + iFuturesConstracts;
		strConsTractName = *it;
		//切割字母和数字；
		for (i = 0; i < (int)strConsTractName.length(); i++)
		{
			if (strConsTractName[i] >= '0'&& strConsTractName[i] <= '9')
			{
				break;
			}
			//将期货合约统一为大写字母表示
			if (strConsTractName[i] >= 97 && strConsTractName[i] <= 122)			//97 是小写a ，122是小写z
			{
				//	|| cConstraction[i] >= 65 && cConstraction[i] <= 90)			//65是大写A ， 90是大写Z
				strConsTractName[i] -= 32;											//小写字母转大写字母，
			}
		}
		strConsTractName = strConsTractName.substr(0, i);		//从字符串0位置开始，截取非数字的期货合约代码

		//获取期货浮动盈亏
		it = vWord.begin() + iProFitsLossOFFloating;
		if (*it == "--")
			fProFitsLossOFFloating = 0;
		else
			fProFitsLossOFFloating = stof(it->c_str());

		//计算全部持仓盈亏
		fTotalProFitsLossOFFloating += fProFitsLossOFFloating;

		//组队并记入
		fTemp = 0;

		//先查找有没有这种品种的交易记录
		pairTemp.first = strInvestorID;
		pairTemp.second = strConsTractName;
		mapIt = mapArr.find(pairTemp);
		if (mapIt != mapArr.end())
		{
			//如果已经有这个品种，只需要在这个品种的浮动盈亏上加减后续盈亏
			fTemp = mapIt->second.first;
			fTemp += fProFitsLossOFFloating;
			mapIt->second.first = fTemp;
		}
		else
		{
			//如果没有这个品种，新开一个品种和盈亏
			mapArr.insert(make_pair(pairTemp, make_pair(fProFitsLossOFFloating, strFileTemp)));
		}
		strFrontInverstorID = *vWord.begin();				//记录上一行的投资者账户
	}

	cout << strFileTemp << " 文件读取完毕！ " << endl;
	fileCSV.close();

	// return (ElasticityResaultToTXT(mapArr, strFileName, "平仓盈亏逐笔.txt"));
	return mapArr;
}


//输入： string strFileName文件名,
//功能： 读取strFileName文件，自适应strFileName中数据的分布顺序、数据列数；
//输出： 返回存储读文件结果的数组mapArr;<string 账户名，string 期货合约代码 ， float 平仓盈亏逐笔统计,string文件名>
map<pair<string, string>, pair<float, string>> ElasticityTransactionCSVFileRead(
	map<pair<string, string>, pair<float, string>>& mapArr,
	string strFileName)
{
	ifstream fileCSV;
	fileCSV.open(strFileName, ios::in);
	string strFileTemp = strFileName.substr(strFileName.rfind('\\') + 1, strFileName.npos);
	if (fileCSV.is_open() == false)
	{
		cout << "读取 " << strFileTemp << "   失败。" << endl
			<< "请保证其他程序不在使用该文件，并关闭本程序再试." << endl;
		fileCSV.close();
		return mapArr;
	}

	string strLine;
	if (!getline(fileCSV, strLine))			 //读取第一行
		return mapArr;						//空文件或者无交易记录文件，结束读取

	//解析第一行
	int iInvestorID = 0;
	int iFuturesConstracts = 0;
	int iTickByTickClosdProfits = 0;
	int i = 0;
	vector<string> vWord;
	string strWord;							//分割后的子串
	stringstream strStreamTemp(strLine);		//字符流
	i = 0;
	while (getline(strStreamTemp, strWord, ','))//以“, ”号字符分割
	{

		if (strWord.compare("投资者账号") == 0)
		{
			iInvestorID = i;					//期货账户所在列数
		}
		if (strWord.compare("合约代码") == 0)
		{
			iFuturesConstracts = i;				//合约代码所在列数
		}
		if (strWord.compare("平仓盈亏(逐笔)") == 0)
		{
			iTickByTickClosdProfits = i;		//计算CSV "平仓盈亏(逐笔)"在的列数,
		}
		i++;
	}

	string strInvestorID;					//账户名
	string strInverstorIDTotal;				//用于记录表格中“全部”一行的账户名
	string strConsTractName;				//期货合约代码
	float fTickByTickClosdProfits;			//平仓盈亏逐笔
	float fTemp = 0;
	vector<string>::iterator it;
	map<pair<string, string>, pair<float, string>>::iterator mapIt;
	pair<string, string> pairTemp;

	//解析成交订单信息的剩余行
	while (getline(fileCSV, strLine))		//逐行读取
	{
		vWord = {};							//初始化
		fTickByTickClosdProfits = 0;
		strStreamTemp = stringstream(strLine);		//字符流
		while (getline(strStreamTemp, strWord, ','))		//以“, ”号字符分割
		{
			vWord.push_back(strWord);
		}

		//获取期货账号
		it = vWord.begin() + iInvestorID;
		strInvestorID = *it;
		if (strInvestorID.compare("全部") >= 0)
		{
			strInvestorID = strInverstorIDTotal;
		}

		//获取期货品种合约代码
		it = vWord.begin() + iFuturesConstracts;
		strConsTractName = *it;
		//切割字母和数字；
		for (i = 0; i < (int)strConsTractName.length(); i++)
		{
			if (strConsTractName[i] >= '0'&& strConsTractName[i] <= '9')
			{
				break;
			}
			//将期货合约统一为大写字母表示
			if (strConsTractName[i] >= 97 && strConsTractName[i] <= 122)			//97 是小写a ，122是小写z
			{
				//	|| cConstraction[i] >= 65 && cConstraction[i] <= 90)			//65是大写A ， 90是大写Z
				strConsTractName[i] -= 32;											//小写字母转大写字母，
			}
		}
		strConsTractName = strConsTractName.substr(0, i);		//从字符串0位置开始，截取非数字的期货合约代码

		//获取期货平仓盈亏逐笔
		it = vWord.begin() + iTickByTickClosdProfits;
		if (*it == "--")
			fTickByTickClosdProfits = 0;
		else
			fTickByTickClosdProfits = stof(it->c_str());

		//组队并记入
		fTemp = 0;

		//先查找有没有这种品种的交易记录
		pairTemp.first = strInvestorID;
		pairTemp.second = strConsTractName;
		mapIt = mapArr.find(pairTemp);
		if (mapIt != mapArr.end())
		{
			//如果已经有这个品种，只需要在这个品种的逐笔盈亏上加减后续盈亏
			//获取tuple的float元素
			fTemp = mapIt->second.first;
			fTemp += fTickByTickClosdProfits;
			mapIt->second.first = fTemp;
		}
		else
		{
			//如果没有这个品种，新开一个品种和盈亏
			mapArr.insert(make_pair(pairTemp, make_pair(fTickByTickClosdProfits, strFileTemp)));
		}
		strInverstorIDTotal = *vWord.begin();				//记录上一行的投资者账户
	}

	cout << strFileTemp << " 文件读取完毕！ " << endl;
	fileCSV.close();

	// return (ElasticityResaultToTXT(mapArr, strFileName, "平仓盈亏逐笔.txt"));
	return mapArr;
}



// 程序版权 、责任声明
void Notification()
{
	cout << "\n************************************************************" << endl << endl
		<< " 本软件为非盈利性程序，代码开源，公开版权，遵守Apache Lience\\BSD规范，仅供学习参考。" << endl
		<< " 开发人员 Sam Smith ，" << endl
		<< " email :sam-nuaa@nuaa.edu.cn" << endl
		<< " github仓库：https://github.com/SamSmithchina/qingsuan.git" << endl << endl
		<< " 使用说明：" << endl
		<< " 1.交易员请在无限易中将“实时持仓”、“成交汇总”两栏文件导出到本地，" << endl
		<< "   文件名为 名字+时间+序号.scv" << endl
		<< "   格式如“实时持仓_2024_05_25-15_28_60.csv”," << endl
		<< "         “成交汇总_2024_05_25-15_28_46.csv”" << endl
		<< " 2.数据文件保存或者拷贝到“日结清算.exe”所在目录下，" << endl
		<< " 3.点击“日结清算.exe”程序，" << endl
		<< " 4.程序只计算今天日期文件，请定期清除旧日期文件，" << endl
		<< " 5.程序根据“实时持仓”表格的“浮动盈亏”、“成交汇总”表格的“平仓逐笔盈亏”，自动完成清算，请按任意键后按回车键确认，退出程序，" << endl
		<< " 6.目录下生成清算结果“平仓盈亏逐笔和浮动盈亏.txt”。" << endl << endl
		<< " 7.当本程序运行异常，请关闭程序，关闭相关文件，然后重启程序" << endl << endl
		<< "************************************************************" << endl
		<< endl << endl << endl << endl << endl;

	long   hFile = 0;				// 文件句柄
	struct _finddata_t fileinfo;	//文件信息
	hFile = _findfirst("日结清算 使用说明.txt", &fileinfo);
	if (hFile == -1)				//不存在使用说明文件
	{
		ofstream of("日结清算 使用说明.txt");
		if (of.is_open())
		{
			cout << "当本程序运行异常，请关闭程序，关闭相关文件，然后重启程序" << endl;
			cout << "Notification error" << endl;
		}

		of << "\n************************************************************" << endl << endl
			<< " 本软件为非盈利性程序，代码开源，公开版权，遵守Apache Lience\\BSD规范，仅供学习参考。" << endl
			<< " 开发人员 Sam Smith ，" << endl
			<< " email :sam-nuaa@nuaa.edu.cn" << endl
			<< " github仓库：https://github.com/SamSmithchina/qingsuan.git" << endl << endl
			<< " 使用说明：" << endl
			<< " 1.交易员请在无限易中将“实时持仓”、“成交汇总”两栏文件导出到本地，" << endl
			<< "   文件名为 名字+时间+序号.scv" << endl
			<< "   格式如“实时持仓_2024_05_25-15_28_60.csv”," << endl
			<< "         “成交汇总_2024_05_25-15_28_46.csv”" << endl
			<< " 2.数据文件保存或者拷贝到“日结清算.exe”所在目录下，" << endl
			<< " 3.点击“日结清算.exe”程序，" << endl
			<< " 4.程序只计算今天日期文件，请定期清除旧日期文件，" << endl
			<< " 5.程序根据“实时持仓”表格的“浮动盈亏”、“成交汇总”表格的“平仓逐笔盈亏”，自动完成清算，请按任意键后按回车键确认，退出程序，" << endl
			<< " 6.目录下生成清算结果“平仓盈亏逐笔和浮动盈亏.txt”。" << endl << endl
			<< " 7.当本程序运行异常，请关闭程序，关闭相关文件，然后重启程序" << endl << endl
			<< "************************************************************" << endl;
		of.close();
	}
}



#endif // !1
