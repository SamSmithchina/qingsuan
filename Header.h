// ����˵��:
// ������Ϊ�������Աÿ���̺�����ӯ������ʹ�á�
// *******
// 
// �뽻��Ա������������ĳֲֺͳɽ����ݺ󣬽������ļ������ڱ�����ͬһ���ļ����С�
// 
// *******
// ������־��202-5-22  
//			 1.�����ڻ�Ʒ������,map�ڲ�������ǰ���洢�ģ���������������������ʵ�ֿ��ٲ��ҡ�
//             �ڲ���<key, value>��ֵ��ʱ��map�ͻ��Զ�����key�Ĵ�С˳����д洢�������Ϊkey�����ͱ����ܹ����д�С����ıȽϡ�
//			 2.�˶�ƽ��ӯ����ʵ�ͳ�Ʒ�����
//           3.github�ֿ⣺https://github.com/SamSmithchina/qingsuan.git
// ������־��202 - 3 - 21
// 
// ���򽫻��ȡ�������ݣ��Զ�����ȫ��Ʒ�֡�ȫ����Լ�ĳֲ�ӯ����ɽ����ӯ����
// ���ǽ������ĳ��ڽ���Ʒ�ָ��»�����δ���Ľ���Ʒ�ִ��벻ȷ�����������н���Ʒ��ʶ��ƥ�书�ܡ�ÿ����Լ�����Զ����ֲ�ʶ��
// ������֡�M2305��ʶ��Ϊ��M��Ʒ�֣���M2305P3800��ʶ��Ϊ��M��Ʒ���¡�P3800����
// ������֡�MK305����ʶ��Ϊ��MK��Ʒ�֣� ��MK305C5800��ʶ��Ϊ��MK��Ʒ��"C5800"��
// 
// �����Ϊ��ӯ���Գ��򣬴��뿪Դ��������Ȩ������Apache Lience\BSD�淶������ѧϰ�ο���
// ������Ա Sam Smith ��
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



// �ɽ� ��,��26��Ԫ�س�Ա
class TRANSACTION
{
	char cInvestorID[20];				//Ͷ�����˺�
	char cINvestorName[256];			//Ͷ����
	char cFuturesConstracts[20];		//��Լ����
	char cFuturesConstractsName[80];	//��Լ����
	char cFuturesExchange[20];			//������
	int iTotal;							//�ϼ���
	int iTurnover;						//���ɽ���
	int iBuyNumber;						//������
	float fBuyAveragePrice;				//�����
	int iSellNumber;					//������
	float fSellAveragePrice;			//������

	int iBuyToOPen;						//��
	float fBuyToOpenAveragePrice;		//�򿪾���
	int iSellToOPen;					//����
	float fSellToOpenAveragePrice;		//��������
	int iBuyToClose;					//��ƽ
	float fBuyToCloseAveragePrice;		//��ƽ����
	int iSellToClose;					//��ƽ
	float fSellToCloseAveragePrice;		//��ƽ����

	//����Ԫ���ڱ�����Ϊ��--������0����ʾ�������ݵ������ݱ�ʾ
	float fServiceCharge;				//������
	float fAverageServiceCharge;		//�����ѣ�ƽ����
	float fClosedProfits;				//ƽ��ӯ��
	float fAverageClosedProfits;		//ƽ��ӯ����ƽ����
	float fTickByTickClosdProfits;		//ƽ��ӯ������ʣ�
	float fAverageTickByTickClosdProfits;//ƽ��ӯ�������ƽ����

	char cUserID[20];						//�µ��û�

public:
	TRANSACTION(){};
	TRANSACTION(vector<string> vStr);
	void Display();							//��ʾ����

	char* GetFuturesConstractsName()		//��ȡƷ����ϵ
	{
		return cFuturesConstracts;
	}

	float GetTickByTickClosdProfits()		//��ȡƽ��ӯ������ʣ�
	{
		return fTickByTickClosdProfits;
	}
	char* GetInvestorID()
	{
		return cInvestorID;
	}
	~TRANSACTION(){};
};

//��ʾ����
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

	strcpy_s(cInvestorID, vStr[i++].c_str());		//Ͷ�����˺�
	strcpy_s(cINvestorName, vStr[i++].c_str());			//Ͷ����
	strcpy_s(cFuturesConstracts, vStr[i++].c_str());		//��Լ����

	strcpy_s(cFuturesConstractsName, vStr[i++].c_str());	//��Լ����

	strcpy_s(cFuturesExchange, vStr[i++].c_str());		//������


	iTotal = stoi(vStr[i++].c_str());						//�ϼ���

	iTurnover = stoi(vStr[i++].c_str());					//���ɽ���

	iBuyNumber = stoi(vStr[i++].c_str());					//������

	fBuyAveragePrice = stof(vStr[i++].c_str());			//�����

	iSellNumber = stoi(vStr[i++].c_str());				//������

	fSellAveragePrice = stof(vStr[i++].c_str());			//������


	iBuyToOPen = stoi(vStr[i++].c_str());					//��

	fBuyToOpenAveragePrice = stof(vStr[i++].c_str());		//�򿪾���

	iSellToOPen = stoi(vStr[i++].c_str());				//����

	fSellToOpenAveragePrice = stof(vStr[i++].c_str());	//��������

	iBuyToClose = stoi(vStr[i++].c_str());				//��ƽ

	fBuyToCloseAveragePrice = stof(vStr[i++].c_str());	//��ƽ����

	iSellToClose = stoi(vStr[i++].c_str());				//��ƽ

	fSellToCloseAveragePrice = stof(vStr[i].c_str()); //��ƽ����

	i++;
	if (vStr[i] == "--")
		fServiceCharge = 0;
	else
		fServiceCharge = stof(vStr[i].c_str());			//������

	i++;
	if (vStr[i] == "--")
		fAverageServiceCharge = 0;
	else
		fAverageServiceCharge = stof(vStr[i].c_str());	//�����ѣ�ƽ����

	i++;
	if (vStr[i] == "--")
		fClosedProfits = 0;
	else
		fClosedProfits = stof(vStr[i].c_str());		//ƽ��ӯ��

	i++;
	if (vStr[i] == "--")
		fAverageClosedProfits = 0;
	else
		fAverageClosedProfits = stof(vStr[i].c_str());//ƽ��ӯ����ƽ����

	i++;
	if (vStr[i] == "--")
		fTickByTickClosdProfits = 0;
	else
		fTickByTickClosdProfits = stof(vStr[i].c_str());//ƽ��ӯ������ʣ�

	i++;
	if (vStr[i] == "--")
		fAverageTickByTickClosdProfits = 0;
	else
		fAverageTickByTickClosdProfits = stof(vStr[i].c_str());//ƽ��ӯ�������ƽ����

	i++;
	strcpy_s(cUserID, vStr[i].c_str());					//�µ��û�
	//cout << "cUserID " << cUserID  << "   i = " << i<< endl;
}


// �ֲ� �࣬��32��Ԫ�س�Ա
class HOLDING
{
	char cInvestorID[20];				//Ͷ�����˺�
	char cINvestorName[256];			//Ͷ����
	char cFuturesExchange[20];			//������
	char cFuturesConstracts[20];		//��Լ����
	char cFuturesConstractsName[80];	//��Լ����
	bool  bBuyORSell;					//���������� 1���� 0
	bool  bType;						//Ͷ�����ͣ�Ͷ�� 1������ 0��
	int	iNUmberOFHeld;					//�ֲ�����
	float fLatestPrice;					//���¼�
	float fAveragePriceOFHeld;			//�ֲ־��ۣ���λ��ЧС��
	float fAveragePriceOFOpenPositions;	//���־��ۣ���λ��ЧС��
	float fProfitsLossOFHOLding;		//�ֲ�ӯ��
	float fProFitsLossOFFloating;		//����ӯ��
	float fPercentage;					//����
	char cStopLossPrice[20];			//ֹ�𴥷���,����ʾĬ��"������"
	char cStopProfitPrice[20];			//ֹӯ�����ۣ�����ʾ Ĭ��"������"
	char cStopNumber[20];				//��������������ʾ��ȫ��������ĳ����Ŀ
	int iYestardayNUmber;				//��ֲ�
	int iTodayNumber;					//��ֲ�
	int iClosePositionNumber;			//��ƽ��
	int iTodayClosePositionNumber;		//��ƽ����
	int iFrozenClosedPpositionnumber;	//ƽ�񶳽�
	int iFrozenExercise = 0;			//��Ȩ����
	int iGiveUpFrozenExercise = 0;;		//������Ȩ����
	int iComposedHOlding = 0;			//��ϳֲ�
	float fOccupiedSecurityDeposit;		//ռ�ñ�֤��,�ٷ�������"--"
	float fpropotionOFFunds;			//�ʽ�ռ��
	bool bHoldingType;					//�ֲ����ͣ������ 1�� Ȩ���� 0��
	float OptionMarketValue;			//��Ȩ��ֵ
	char* cCurrency = NULL;				//���֣�Ĭ���ޱ���
	float fExchangeRate = 1;			//����,Ĭ��1
	int iTASHolding = 0;				//TAS�ֲ֣�Ĭ��0

public:
	HOLDING()
	{
		cStopLossPrice[20] = '?';		//ֹ�𴥷���,����ʾĬ��"������"
		cStopProfitPrice[20] = '?';		//ֹӯ�����ۣ�����ʾ Ĭ��"������"
		cStopNumber[20] = '?';			//��������������ʾ��ȫ����,���߸���ָ���޸�ĳ����Ŀ
	}
	HOLDING(vector<string> vStr);
	~HOLDING(){};
	float GetProFitsFloating()			//��ȡ����ӯ��
	{
		return fProFitsLossOFFloating;
	}

	char* GetFuturesConstracts()		//��ȡ��Լ����
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
	//char cInvestorID[20];					//Ͷ�����˺�
	strcpy_s(cInvestorID, it->c_str());
	it++;
	//char cINvestorName[256];				//Ͷ����
	strcpy_s(cINvestorName, it->c_str());
	it++;
	//char cFuturesExchange[20];			//������
	strcpy_s(cFuturesExchange, it->c_str());
	it++;
	//char cFuturesConstracts[20];			//��Լ����
	strcpy_s(cFuturesConstracts, it->c_str());
	it++;

	//char cFuturesConstractsName[80];		//��Լ����
	strcpy_s(cFuturesConstractsName, it->c_str());
	it++;

	//bool  bBuyORSell;						//���������� 1���� 0
	if (*it == "1")
	{
		bBuyORSell = true;
	}
	else
	{
		bBuyORSell = false;
	}
	it++;

	//bool  bType;							//Ͷ�����ͣ�Ͷ�� 1������ 0��
	if (*it == "1")
	{
		bType = true;
	}
	else
	{
		bType = false;
	}
	it++;

	//int	iNUmberOFHeld;					//�ֲ�����
	iNUmberOFHeld = stoi(it->c_str());
	it++;
	//float fLatestPrice;					//���¼�
	fLatestPrice = stof(it->c_str());
	it++;

	//float fAveragePriceOFHeld;			//�ֲ־��ۣ���λ��ЧС��
	fAveragePriceOFHeld = stof(it->c_str());
	it++;
	//float fAveragePriceOFOpenPositions;	//���־��ۣ���λ��ЧС��
	fAveragePriceOFOpenPositions = stof(it->c_str());
	it++;
	//float fProfitsLossOFHOLding;			//�ֲ�ӯ��
	fProfitsLossOFHOLding = stof(it->c_str());
	it++;
	//float fProFitsLossOFFloating;			//����ӯ��
	if (*it == "--")
		fProFitsLossOFFloating = 0;
	else
		fProFitsLossOFFloating = stof(it->c_str());
	it++;
	//float fPercentage;					//����
	fPercentage = stof(it->c_str());
	it++;
	//char cStopLossPrice[20];					//ֹ�𴥷���,����ʾĬ��"������"
	strcpy_s(cStopLossPrice, it->c_str());
	it++;
	//char cStopProfitPrice[20];				//ֹӯ�����ۣ�����ʾ Ĭ��"������"
	strcpy_s(cStopProfitPrice, it->c_str());
	it++;
	//char cStopNumber[20];						//��������������ʾ��ȫ��������ĳ����Ŀ
	strcpy_s(cStopNumber, it->c_str());
	it++;

	//int iYestardayNUmber;						//��ֲ�
	iYestardayNUmber = stoi(it->c_str());
	it++;
	//int iTodayNumber;							//��ֲ�
	iTodayNumber = stoi(it->c_str());
	it++;
	//int iClosePositionNumber;					//��ƽ��
	iClosePositionNumber = stoi(it->c_str());
	it++;
	//int iTodayClosePositionNumber;			//��ƽ����
	iTodayClosePositionNumber = stoi(it->c_str());
	it++;
	//int iFrozenClosedPpositionnumber;			//ƽ�񶳽�
	iFrozenClosedPpositionnumber = stoi(it->c_str());
	it++;

	iFrozenExercise = 0;						//��Ȩ����
	iGiveUpFrozenExercise = 0;;				//������Ȩ����
	iComposedHOlding = 0;						//��ϳֲ�

	//float fOccupiedSecurityDeposit;			//ռ�ñ�֤��,�ٷ�������"--"
	fOccupiedSecurityDeposit = stof(it->c_str());
	it++;
	//float fpropotionOFFunds;					//�ʽ�ռ��
	fpropotionOFFunds = stof(it->c_str());
	it++;
	//bool bHoldingType;						//�ֲ����ͣ������ 1�� Ȩ���� 0��
	if (*it == "1")
		bHoldingType = true;
	else
		bHoldingType = false;
	it++;

	//float OptionMarketValue;					//��Ȩ��ֵ
	OptionMarketValue = stof(it->c_str());
	it++;

	char* cCurrency = NULL;						//���֣�Ĭ���ޱ���
	float fExchangeRate = 1;					//����,Ĭ��1
	int iTASHolding = 0;						//TAS�ֲ֣�Ĭ��0

}

//���룺
//��ȡstring����������ʱ��
//�����string�����գ����硰2023_03_21��
string GetTime()
{
	//��ȡ�������ڣ�
	time_t timeNow;
	string strTime;
	time(&timeNow);//��ȡ1970��1��1��0��0��0�뵽���ھ���������
	tm p;
	int i = 0;
	localtime_s(&p, &timeNow);

	//������ת��Ϊ����ʱ��,���1900����,��Ҫ+1900,��Ϊ0-11,������Ҫ+1
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
	//cout << "��ǰʱ�� �� " << strTime << endl;
	return strTime;
}




// ���룺�������ļ��ǡ��ɽ����ܡ����ߡ�ʵʱ�ֲ֡�
// �����ļ����µĳɽ�����CSV�ļ�����ʵʱ�ֲ�CSV�ļ�
// �����һ����¼�ɽ����ܻ��ֲ߳�CSV�ļ���CSV�ļ�����string��
vector<string>  SearchCSVFile(string strFile)
{
	int iFlag = -1;
	char cwd[256];
	_getcwd(cwd, 256);
	string strTempDir = cwd;			//ִ�г���ǰ·����
	strTempDir.append("\\*");

	const string strFileType = ".csv";	//ָ���ļ�����
	long   hFile = 0;					// �ļ����
	vector<string> vecFiles;			//�洢���ϵ��ļ���
	struct _finddata_t fileinfo;		//�ļ���Ϣ
	string strTime;
	string strTempFile;
	string strPath;

	hFile = _findfirst(strTempDir.c_str(), &fileinfo);
	if (hFile != -1) //�����ļ�
	{
		do {
			strTempFile = fileinfo.name;
			if (strTempFile.find(strFile) != string::npos)
			{
				strTime = GetTime();							//�ļ����ָ�ʽ�硰ʵʱ�ֲ�_2023_03_21-15_28_49.csv��
				if (strTempFile.find(strTime) != string::npos  //���ؼ��ֺ�csv��ʽѰ���ļ�
					&& strTempFile.find(strFileType) != string::npos)
				{
					strPath = cwd;
					vecFiles.push_back(strPath.append("\\").append(strTempFile));
				}
			}

		} while (_findnext(hFile, &fileinfo) == 0);  //Ѱ����һ�����ɹ�����0������-1
		_findclose(hFile);		//close
	}

	return vecFiles;
}


// ���룺 �ֲ���
// �ֲ��ļ���ȡ,��ȡ�����׵�ʵʱ�ֲ�***.csv��ʽ�ļ����洢�ڳֲ�����
// ����� 0�� ������ɶ�ȡ��-1����ȡ�����쳣
//int HlodingCSVFileRead(string strFileName)
int HlodingCSVFileRead(vector<HOLDING> &Holding, string strFile)
{
	ifstream fileCSV;
	fileCSV.open(strFile, ios::in);
	string strFileTemp = strFile.substr(strFile.rfind('\\') + 1, strFile.npos);
	if (fileCSV.is_open() == false)
	{
		cout << "��ȡ " << strFileTemp << "   ʧ�ܡ�" << endl
			<< "�뱣֤����������ʹ�ø��ļ������رձ���������." << endl;
		fileCSV.close();
		return -1; //�����쳣����
	}

	string strLine;
	if (!getline(fileCSV, strLine))			 //��ȡ��һ��
		return -1;							//���ļ������޽��׼�¼�ļ�������-1

	HOLDING HoldingTemp;
	vector<string> vWord;
	string strWord;
	string strTemp;
	//�����ɽ�������Ϣ
	while (getline(fileCSV, strLine))		//���ж�ȡ
	{
		vWord = {};							//��ʼ��
		stringstream strTemp(strLine);		//�ַ���
		while (getline(strTemp, strWord, ','))		//�ԡ�, �����ַ��ָ�
		{
			vWord.push_back(strWord);
		}
		//��ʼ��
		HoldingTemp = HOLDING(vWord);
		//��ȡһ�м�¼
		Holding.push_back(HoldingTemp);
	}

	cout << strFileTemp << " �ļ���ȡ��ϣ� " << endl;
	fileCSV.close();
	return 0;

}

//���� ��  map<pair<string, string>, pair<float, string>> mapHolding,
//���� ��  ����ÿ��Ͷ�����˻��µ�ȫ���ֲָ���ӯ������mapHolding�в���<Ͷ���ߡ���ȫ������flaot����ӯ����string �ļ�����>
//��� ��  mapHolding
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
		//��ȡ��һ��ָ��
		itMapNext = ++itMap;
		itMap--;
		if (itMapNext == mapHolding.end())
		{
			mapHolding.insert(make_pair(make_pair(itMap->first.first, "ȫ��"), make_pair(fTotal, itMap->second.second)));
		}
		else if (itMapNext != mapHolding.end())
		{
			if (itMapNext->first.first != itMap->first.first)
				mapHolding.insert(make_pair(make_pair(itMap->first.first, "ȫ��"), make_pair(fTotal, itMap->second.second)));
		}
	}

	return mapHolding;
}

//���룺 map<pair<string, string>, pair<float, string>> mapTranscation,
//		 map<pair<string, string>, pair<float, string>> mapHolding,
//���ܣ� �ϲ�����map,
//����� �ϲ����map,����<<Ͷ���ߣ��ڻ���������>��<ƽ��ӯ�����ֲ�ӯ��>>����<Ͷ����,�ڻ�����>������������
map<pair< string, string >, pair< float, float >> MergeMap(
	map<pair<string, string>, pair<float, string>> mapTranscation,
	map<pair<string, string>, pair<float, string>> mapHolding)
{
	//��¼���ս����map
	map<pair<string, string>, pair<float, float>> mapResult;
	//������
	map<pair<string, string>, pair<float, string>>::iterator mapTransIt;
	map<pair<string, string>, pair<float, string>>::iterator mapHoldingIt;

	//����ֲ�ӯ������
	mapHolding = TotalMapHoling(mapHolding);

	//�ȴ���mapTranscation
	for (mapTransIt = mapTranscation.begin(); mapTransIt != mapTranscation.end(); mapTransIt++)
	{
		//���Ҷ���Ͷ�����˻��ض�Ʒ�ִ���ĸ���ӯ��
		mapHoldingIt = mapHolding.find(mapTransIt->first);
		//��Ͷ�����˻��ض�Ʒ�ִ����µĸ���ӯ����ƽ��ӯ��
		if (mapHoldingIt != mapHolding.end())
		{
			//�洢���
			mapResult.insert(make_pair(mapTransIt->first, make_pair(mapTransIt->second.first, mapHoldingIt->second.first)));
		}
		// �ֲָ���ӯ�� = 0��ֻ��ƽ��ӯ��
		else
		{
			//�洢���
			mapResult.insert(make_pair(mapTransIt->first, make_pair(mapTransIt->second.first, 0)));
		}

	}
	//�������ƽ��ӯ��������ʣ�µĳֲָ���ӯ��
	for (mapHoldingIt = mapHolding.begin(); mapHoldingIt != mapHolding.end(); mapHoldingIt++)
	{
		//���Ҷ���Ͷ�����˻��ض�Ʒ�ִ����ƽ��
		mapTransIt = mapTranscation.find(mapHoldingIt->first);
		//��Ͷ�����˻��ض�Ʒ�ִ����µĸ���ӯ����ƽ��ӯ��,��ǰ���Ѿ�������ɣ�
		if (mapTransIt != mapTranscation.end())
			continue;	//ֱ���������ô���
		else
		{
			//�洢���
			// ֻ�гֲָ���ӯ����ƽ��ӯ��= 0
			mapResult.insert(make_pair(mapHoldingIt->first, make_pair(0, mapHoldingIt->second.first)));
		}
	}


	return mapResult;
}

//���룺�洢���ļ����������mapArr;<string �˻�����string �ڻ���Լ���� �� float ƽ��ӯ�����ͳ�ƣ�float ����ӯ��>
//      Դ�ļ� strFile ����������ļ�strResultFile��
//���ܣ�������д��ָ���ļ� ƽ��ӯ�����.txt
//�����0 ����д��-1 �쳣
int ElasticityTotalResaultToTXT(
	map<pair< string, string >, pair< float, float >> mergeMap,
	string strResultFile)
{
	ofstream of;
	of.open(strResultFile, ofstream::app);
	if (!of.is_open())
	{
		cout << "��" << strResultFile << "�ļ�ʧ�ܣ�\n ��ر���������ʹ�ø��ļ��ĳ���" << endl;
		return -1;
	}

	//�ϲ�

	//bool bFlag = false;
	const string str1 = "------------------------------------------------------";
	const string str2 = "                                                      ";
	const string str3 = "��Լ����";
	const string str4 = "ƽ��ӯ�����";
	const string str5 = "�ֲ�ӯ��";
	string str6 = "";
	//�ڻ�Ʒ�ְ�Ӣ����ĸA - Z˳������,
	map<pair<string, string>, pair<float, float>>::iterator mapIt = mergeMap.begin();
	string strInvestorID = "";
	string strFrontInvestorID = "";
	string strConstractsName = "";
	float fProFitsLossOFFloating = 0;
	float ffTickByTickClosdProfits;


	while (mapIt != mergeMap.end())
	{
		//�ļ���

		//Ͷ�����˻�
		strInvestorID = mapIt->first.first;
		if (strFrontInvestorID != strInvestorID)
		{
			/*
			of << endl << strFile << "  ͳ�����£�" << endl;
			cout << endl << strFile << "  ͳ�����£�" << endl;
			*/
			//�̶���������ʽ
			of << endl << "�˺�   " << strInvestorID << endl
				<< "|" << str1 << "|" << endl
				<< "|  " << left << setw(10) << str3
				<< "|  " << left << setw(18) << str4
				<< "|  " << left << setw(18) << str5 << "|" << endl
				<< "|" << str1 << "|" << endl;
			cout << endl << "�˺�   " << strInvestorID << endl
				<< "|" << str1 << "|" << endl
				<< "|  " << left << setw(10) << str3
				<< "|  " << left << setw(18) << str4
				<< "|  " << left << setw(18) << str5 << "|" << endl
				<< "|" << str1 << "|" << endl;
		}

		//�ڻ���Լ����
		strConstractsName = mapIt->first.second;
		//�̶���������ʽ
		if (strConstractsName.compare("ȫ��") >= 0)
		{
			//bFlag = true;
			of << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;

			cout << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;
		}

		// ͳ������ӯ��
		ffTickByTickClosdProfits = mapIt->second.first;
		fProFitsLossOFFloating = mapIt->second.second;

		// ����ڻ�Ʒ������
		if (strConstractsName.size() > 3)
			of << "|  " << left << setw(11) << strConstractsName;
		else
			of << "|  " << left << setw(10) << strConstractsName;
		cout << "|  " << left << setw(10) << strConstractsName;

		//���ƽ��ӯ����ʺ͸���ӯ��
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
		<< "ͳ�ƽ�������� : " << strResultFile << endl << endl << endl;

	of.close();
	return 0;
}

//���룺�洢���ļ����������mapArr;<string �˻�����string �ڻ���Լ���� �� float ƽ��ӯ�����ͳ��>
//      Դ�ļ� strFile ����������ļ�strResultFile��
//���ܣ�������д��ָ���ļ� ƽ��ӯ�����.txt
//�����0 ����д��-1 �쳣
int ElasticityResaultToTXT(map<pair<string, string>, pair<float, string>> mapArr, string strResultFile)
{
	ofstream of;
	of.open(strResultFile, ofstream::app);
	if (!of.is_open())
	{
		cout << "��" << strResultFile << "�ļ�ʧ�ܣ�\n ��ر���������ʹ�ø��ļ��ĳ���" << endl;
		return -1;
	}
	if (mapArr.size() == 0)
	{
		return 0;
	}

	//bool bFlag = false;
	const string str1 = "---------------------------------";
	const string str2 = "                                 ";
	//�ڻ�Ʒ�ְ�Ӣ����ĸA - Z˳������,
	map<pair<string, string>, pair<float, string>>::iterator mapIt = mapArr.begin();
	string strInvestorID = "";
	string strFrontInvestorID = "";
	string strConstractsName = "";
	float fProfits = 0;
	string strFile = "";


	while (mapIt != mapArr.end())
	{
		////�ļ���
		strFile = mapIt->second.second;


		strInvestorID = mapIt->first.first;
		if (strFrontInvestorID != strInvestorID)
		{
			of << endl << strFile << "  ͳ�����£�" << endl;
			cout << endl << strFile << "  ͳ�����£�" << endl;

			of << endl << "�˺�   " << strInvestorID << endl
				<< "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;
			cout << endl << "�˺�   " << strInvestorID << endl
				<< "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;
		}

		strConstractsName = mapIt->first.second;
		//�̶���������ʽ
		if (strConstractsName.compare("ȫ��") >= 0)
		{
			//bFlag = true;
			of << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;

			cout << "|" << str1 << "|" << endl
				<< "|" << str2 << "|" << endl;
		}

		fProfits = mapIt->second.first;
		strFile = mapIt->second.second;
		// ����ڻ�Ʒ������
		if (strConstractsName.size() > 3)
			of << "|  " << left << setw(11) << strConstractsName;
		else
			of << "|  " << left << setw(10) << strConstractsName;
		//�������ӯ��
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

//���룺map<string,float> �ṹ��<Ʒ��,���ӯ��>�� 
//      �˻�Ψһ�˺� strInvestorID,Դ�ļ� strFile ����������ļ�strResultFile��
//���ܣ�������д��ָ���ļ�
//�����0 ����д��-1 �쳣
int ResaultToTXT(map<string, float> mapArr, string strInvestorID, string strFile, string strResultFile)
{
	ofstream of;
	of.open(strResultFile, ofstream::app);
	if (!of.is_open())
	{
		cout << "��" << strResultFile << "�ļ�ʧ�ܣ�\n ��ر���������ʹ�ø��ļ��ĳ���" << endl;
		return -1;
	}
	if (mapArr.size() == 0)
	{
		return 0;
	}

	bool bFlag = false;
	const string str1 = "---------------------------------";
	const string str2 = "                                 ";

	//�ڻ�Ʒ�ְ�Ӣ����ĸA - Z˳������
	map<string, float>::iterator mapIt = mapArr.begin();
	string strTemp = strFile.substr(strFile.rfind('\\') + 1, strFile.npos);		//�ļ���
	of << strTemp << "  ͳ�����£�" << endl;
	of << endl << "�˺�   " << strInvestorID << endl
		<< "|" << str1 << "|" << endl
		<< "|" << str2 << "|" << endl;
	cout << endl << "�˺�   " << strInvestorID << endl
		<< "|" << str1 << "|" << endl
		<< "|" << str2 << "|" << endl;

	while (mapIt != mapArr.end())
	{
		//�̶���������ʽ
		if (mapIt->first.compare("ȫ��") >= 0 && bFlag == false)
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

//���룺�ֲֻ�����HOLDING ��vector���飬Դ�ļ��� strFile
//���ܣ��ڻ�Ʒ�ֱ�����Сд��ĸ��ʾ�� m �󶹣�ru ��
//		ͳ��ÿ����Լ��ƽ��ӯ������ʣ�,���д�����ֲָ���ӯ��.txt����
//�����0��ʾִ��������-1 ��ʾִ���쳣
int HoldingProfitsFloating(vector<HOLDING> vHolding, string strFile)
{
	map<string, float> mapArr;			//���ݼ�mapArr��ͳ��Ʒ�ֺ�ƽ��ӯ�����
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

	for (; holdIt != vHolding.end(); holdIt++) //���ͳ�Ƴɽ�����
	{
		iFuture = 0;		//�����ڻ�
		bOption = false;	//������Ȩ
		bNumber = false;	//û�к�Լʱ��

		//ȡ��ȡ����Լ
		cConstraction = holdIt->GetFuturesConstracts();

		//ȡ���ڻ�ƽ�����ӯ��
		fProfits = holdIt->GetProFitsFloating();
		fTotal += fProfits;

		for (i = 0; i <(int)strlen(cConstraction); i++)
		{
			//if (cConstraction[i] >= 97 && cConstraction[i] <= 122			//97 ��Сдa ��122��Сдz
			//	|| cConstraction[i] >= 65 && cConstraction[i] <= 90)		//65�Ǵ�дA �� 90�Ǵ�дZ
			if (cConstraction[i]>57 || cConstraction[i] < 48)				//48������0, 57������9
			{
				if (bOption == false && bNumber == false)					//���ڻ�������Ȩ
				{

					iFuture++;				//�ȴ����ڻ���Լ����
				}
				if (bNumber == true && bOption == false)
				{
					bOption = true;			//����Ȩ��Լ
					break;
				}
			}
			else							//��������
			{
				bNumber = true;				//��Ȩ�Ż����ڻ���Լ���P��C��ʾ�˺��Ϲ�
			}
		}

		//�����ڻ�����Ȩ�ĺ�Լ����
		str.clear();
		//if (bOption == true)
		//{
		//	str.append(cConstraction, iFuture);
		//	str += " ��Ȩ";	//ע������Ȩ����������ʾ����

		//}
		//else
		str.append(cConstraction, iFuture);

		//�Ȳ�����û������Ʒ�ֵĽ��׼�¼��
		mapIt = mapArr.find(str);
		if (mapIt != mapArr.end())
		{
			//����Ѿ������Ʒ�֣�ֻ��Ҫ�����Ʒ�ֵ����ӯ���ϼӼ�����ӯ��
			mapIt->second = mapIt->second + fProfits;
		}
		else
		{
			//���û�����Ʒ�֣��¿�һ��Ʒ�ֺ�ӯ��
			mapArr.insert(pair<string, float>(str, fProfits));
		}
	}
	mapArr.insert(pair<string, float>("ȫ��", fTotal));
	return (ResaultToTXT(mapArr, strInvestorID, strFile, "�ֲָ���ӯ��.txt"));
}


//����
//�ɽ������ļ���ȡ
//����� 0�� ������ɶ�ȡ��-1����ȡ�����쳣
int TransactionCSVFileRead(vector<TRANSACTION>& Trans, string strFile)
{
	ifstream fileCSV;
	fileCSV.open(strFile, ios::in);
	string strFileTemp = strFile.substr(strFile.rfind('\\') + 1, strFile.npos);
	if (fileCSV.is_open() == false)
	{
		cout << "��ȡ " << strFileTemp << "   ʧ�ܡ�" << endl
			<< "�뱣֤����������ʹ�ø��ļ������رձ���������." << endl;
		fileCSV.close();
		return -1; //�����쳣����
	}

	string strLine;
	if (!getline(fileCSV, strLine))			 //��ȡ��һ��
		return -1;							//���ļ������޽��׼�¼�ļ�������-1

	TRANSACTION TransTemp;
	vector<string> vWord;
	string strWord;
	string strTemp;
	//�����ɽ�������Ϣ
	while (getline(fileCSV, strLine))		//���ж�ȡ
	{
		vWord = {};							//��ʼ��
		stringstream strTemp(strLine);		//�ַ���
		while (getline(strTemp, strWord, ','))		//�ԡ�, �����ַ��ָ�
		{
			vWord.push_back(strWord);
		}
		//��ʼ��
		TransTemp = TRANSACTION(vWord);
		//��ȡһ�м�¼
		Trans.push_back(TransTemp);
	}

	cout << strFileTemp << " �ļ���ȡ��ϣ� " << endl;
	fileCSV.close();
	return 0;

}



//���룺�ɽ�������TRANSCATION ��vector���飬�ɽ������ļ���strFile
//���ܣ��ڻ�Ʒ�ֱ�����Сд��ĸ��ʾ�� m �󶹣�ru ��
//		ͳ��ÿ����Լ��ƽ��ӯ������ʣ�,���д����ƽ��ӯ�����.txt����
//�����0��ʾִ��������-1 ��ʾִ���쳣
int TickByTickTransactionProfits(vector<TRANSACTION> vTrans, string strFile)
{
	map<string, float> mapArr;			//���ݼ�mapArr��ͳ��Ʒ�ֺ�ƽ��ӯ�����
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

	for (; transIt != vTrans.end(); transIt++) //���ͳ�Ƴɽ�����
	{
		iFuture = 0;		//�����ڻ�
		bOption = false;	//������Ȩ
		bNumber = false;	//û�к�Լʱ��

		//ȡ��ȡ����Լ
		cConstraction = transIt->GetFuturesConstractsName();

		//ȡ���ڻ�ƽ�����ӯ��
		fProfits = transIt->GetTickByTickClosdProfits();

		for (i = 0; cConstraction[i] != '\0'; i++)
		{
			//���ڻ���ԼͳһΪ��д��ĸ��ʾ
			if (cConstraction[i] >= 97 && cConstraction[i] <= 122)			//97 ��Сдa ��122��Сдz
			{
				//	|| cConstraction[i] >= 65 && cConstraction[i] <= 90)	//65�Ǵ�дA �� 90�Ǵ�дZ
				cConstraction[i] -= 32;										//Сд��ĸת��д��ĸ��
			}
			if (cConstraction[i] > 57 || cConstraction[i] < 48)				//48������0, 57������9
			{
				if (bOption == false && bNumber == false)					//���ڻ�������Ȩ
				{

					iFuture++;				//�ȴ����ڻ���Լ����
				}
				if (bNumber == true && bOption == false)
				{
					bOption = true;			//����Ȩ��Լ
					break;
				}
			}
			else							//��������
			{
				bNumber = true;				//��Ȩ�Ż����ڻ���Լ���P��C��ʾ�˺��Ϲ�
			}
		}

		//��¼�µ��û��˻�


		//�����ڻ�����Ȩ�ĺ�Լ����
		str.clear();
		//if (bOption == true)
		//{
		//	str.append(cConstraction, iFuture);
		//	str += " ��Ȩ";	//ע������Ȩ����������ʾ����
		//}
		//else
		str.append(cConstraction, iFuture);

		//�Ȳ�����û������Ʒ�ֵĽ��׼�¼��
		mapIt = mapArr.find(str);
		if (mapIt != mapArr.end())
		{
			//����Ѿ������Ʒ�֣�ֻ��Ҫ�����Ʒ�ֵ����ӯ���ϼӼ�����ӯ��
			mapIt->second = mapIt->second + fProfits;
		}
		else
		{
			//���û�����Ʒ�֣��¿�һ��Ʒ�ֺ�ӯ��
			mapArr.insert(pair<string, float>(str, fProfits));
		}
	}

	//	map<string ,string ,float> mapArray
	return (ResaultToTXT(mapArr, strInvestorID, strFile, "ƽ��ӯ�����.txt"));
}


//���룺 string strFileName�ļ���,
//���ܣ� ��ȡstrFileName�ļ�������ӦstrFileName�����ݵķֲ�˳������������
//����� ���ش洢���ļ����������mapArr;<string �˻�����string �ڻ���Լ���� �� float ƽ��ӯ�����ͳ��,string�ļ���>
map<pair<string, string>, pair<float, string>> ElasticityHoldingCSVFileRead(
	map<pair<string, string>, pair<float, string>>& mapArr,
	string strFileName)
{
	ifstream fileCSV;
	fileCSV.open(strFileName, ios::in);
	string strFileTemp = strFileName.substr(strFileName.rfind('\\') + 1, strFileName.npos);
	if (fileCSV.is_open() == false)
	{
		cout << "��ȡ " << strFileTemp << "   ʧ�ܡ�" << endl
			<< "�뱣֤����������ʹ�ø��ļ������رձ���������." << endl;
		fileCSV.close();
		return mapArr;
	}

	string strLine;
	if (!getline(fileCSV, strLine))			 //��ȡ��һ��
		return mapArr;						//���ļ������޽��׼�¼�ļ���������ȡ

	//������һ��
	int iInvestorID = 0;
	int iFuturesConstracts = 0;
	int iProFitsLossOFFloating = 0;
	int i = 0;
	vector<string> vWord;
	string strWord;							//�ָ����Ӵ�
	stringstream strStreamTemp(strLine);		//�ַ���
	i = 0;
	while (getline(strStreamTemp, strWord, ','))//�ԡ�, �����ַ��ָ�
	{
		if (strWord.compare("Ͷ�����˺�") == 0)
		{
			iInvestorID = i;					//�ڻ��˻���������
		}
		if (strWord.compare("��Լ����") == 0)
		{
			iFuturesConstracts = i;				//��Լ������������
		}
		if (strWord.compare("����ӯ��") == 0)
		{
			iProFitsLossOFFloating = i;		//����CSV "ƽ��ӯ��(���)"�ڵ�����,
		}
		i++;
	}

	string strInvestorID;					//�˻���
	string strFrontInverstorID;				//���ڼ�¼����С�ȫ����һ�е��˻���
	string strConsTractName;				//�ڻ���Լ����
	float fProFitsLossOFFloating;			//����ӯ��
	float fTotalProFitsLossOFFloating = 0;
	float fTemp = 0;
	vector<string>::iterator it;
	map<pair<string, string>, pair<float, string>>::iterator mapIt;
	pair<string, string> pairTemp;

	//�����ɽ�������Ϣ��ʣ����
	while (getline(fileCSV, strLine))		//���ж�ȡ
	{
		vWord = {};							//��ʼ��
		fProFitsLossOFFloating = 0;
		fTotalProFitsLossOFFloating = 0;
		strStreamTemp = stringstream(strLine);		//�ַ���
		while (getline(strStreamTemp, strWord, ','))		//�ԡ�, �����ַ��ָ�
		{
			vWord.push_back(strWord);
		}

		//��ȡ�ڻ��˺�
		it = vWord.begin() + iInvestorID;
		strInvestorID = *it;


		//��ȡ�ڻ�Ʒ�ֺ�Լ����
		it = vWord.begin() + iFuturesConstracts;
		strConsTractName = *it;
		//�и���ĸ�����֣�
		for (i = 0; i < (int)strConsTractName.length(); i++)
		{
			if (strConsTractName[i] >= '0'&& strConsTractName[i] <= '9')
			{
				break;
			}
			//���ڻ���ԼͳһΪ��д��ĸ��ʾ
			if (strConsTractName[i] >= 97 && strConsTractName[i] <= 122)			//97 ��Сдa ��122��Сдz
			{
				//	|| cConstraction[i] >= 65 && cConstraction[i] <= 90)			//65�Ǵ�дA �� 90�Ǵ�дZ
				strConsTractName[i] -= 32;											//Сд��ĸת��д��ĸ��
			}
		}
		strConsTractName = strConsTractName.substr(0, i);		//���ַ���0λ�ÿ�ʼ����ȡ�����ֵ��ڻ���Լ����

		//��ȡ�ڻ�����ӯ��
		it = vWord.begin() + iProFitsLossOFFloating;
		if (*it == "--")
			fProFitsLossOFFloating = 0;
		else
			fProFitsLossOFFloating = stof(it->c_str());

		//����ȫ���ֲ�ӯ��
		fTotalProFitsLossOFFloating += fProFitsLossOFFloating;

		//��Ӳ�����
		fTemp = 0;

		//�Ȳ�����û������Ʒ�ֵĽ��׼�¼
		pairTemp.first = strInvestorID;
		pairTemp.second = strConsTractName;
		mapIt = mapArr.find(pairTemp);
		if (mapIt != mapArr.end())
		{
			//����Ѿ������Ʒ�֣�ֻ��Ҫ�����Ʒ�ֵĸ���ӯ���ϼӼ�����ӯ��
			fTemp = mapIt->second.first;
			fTemp += fProFitsLossOFFloating;
			mapIt->second.first = fTemp;
		}
		else
		{
			//���û�����Ʒ�֣��¿�һ��Ʒ�ֺ�ӯ��
			mapArr.insert(make_pair(pairTemp, make_pair(fProFitsLossOFFloating, strFileTemp)));
		}
		strFrontInverstorID = *vWord.begin();				//��¼��һ�е�Ͷ�����˻�
	}

	cout << strFileTemp << " �ļ���ȡ��ϣ� " << endl;
	fileCSV.close();

	// return (ElasticityResaultToTXT(mapArr, strFileName, "ƽ��ӯ�����.txt"));
	return mapArr;
}


//���룺 string strFileName�ļ���,
//���ܣ� ��ȡstrFileName�ļ�������ӦstrFileName�����ݵķֲ�˳������������
//����� ���ش洢���ļ����������mapArr;<string �˻�����string �ڻ���Լ���� �� float ƽ��ӯ�����ͳ��,string�ļ���>
map<pair<string, string>, pair<float, string>> ElasticityTransactionCSVFileRead(
	map<pair<string, string>, pair<float, string>>& mapArr,
	string strFileName)
{
	ifstream fileCSV;
	fileCSV.open(strFileName, ios::in);
	string strFileTemp = strFileName.substr(strFileName.rfind('\\') + 1, strFileName.npos);
	if (fileCSV.is_open() == false)
	{
		cout << "��ȡ " << strFileTemp << "   ʧ�ܡ�" << endl
			<< "�뱣֤����������ʹ�ø��ļ������رձ���������." << endl;
		fileCSV.close();
		return mapArr;
	}

	string strLine;
	if (!getline(fileCSV, strLine))			 //��ȡ��һ��
		return mapArr;						//���ļ������޽��׼�¼�ļ���������ȡ

	//������һ��
	int iInvestorID = 0;
	int iFuturesConstracts = 0;
	int iTickByTickClosdProfits = 0;
	int i = 0;
	vector<string> vWord;
	string strWord;							//�ָ����Ӵ�
	stringstream strStreamTemp(strLine);		//�ַ���
	i = 0;
	while (getline(strStreamTemp, strWord, ','))//�ԡ�, �����ַ��ָ�
	{

		if (strWord.compare("Ͷ�����˺�") == 0)
		{
			iInvestorID = i;					//�ڻ��˻���������
		}
		if (strWord.compare("��Լ����") == 0)
		{
			iFuturesConstracts = i;				//��Լ������������
		}
		if (strWord.compare("ƽ��ӯ��(���)") == 0)
		{
			iTickByTickClosdProfits = i;		//����CSV "ƽ��ӯ��(���)"�ڵ�����,
		}
		i++;
	}

	string strInvestorID;					//�˻���
	string strInverstorIDTotal;				//���ڼ�¼����С�ȫ����һ�е��˻���
	string strConsTractName;				//�ڻ���Լ����
	float fTickByTickClosdProfits;			//ƽ��ӯ�����
	float fTemp = 0;
	vector<string>::iterator it;
	map<pair<string, string>, pair<float, string>>::iterator mapIt;
	pair<string, string> pairTemp;

	//�����ɽ�������Ϣ��ʣ����
	while (getline(fileCSV, strLine))		//���ж�ȡ
	{
		vWord = {};							//��ʼ��
		fTickByTickClosdProfits = 0;
		strStreamTemp = stringstream(strLine);		//�ַ���
		while (getline(strStreamTemp, strWord, ','))		//�ԡ�, �����ַ��ָ�
		{
			vWord.push_back(strWord);
		}

		//��ȡ�ڻ��˺�
		it = vWord.begin() + iInvestorID;
		strInvestorID = *it;
		if (strInvestorID.compare("ȫ��") >= 0)
		{
			strInvestorID = strInverstorIDTotal;
		}

		//��ȡ�ڻ�Ʒ�ֺ�Լ����
		it = vWord.begin() + iFuturesConstracts;
		strConsTractName = *it;
		//�и���ĸ�����֣�
		for (i = 0; i < (int)strConsTractName.length(); i++)
		{
			if (strConsTractName[i] >= '0'&& strConsTractName[i] <= '9')
			{
				break;
			}
			//���ڻ���ԼͳһΪ��д��ĸ��ʾ
			if (strConsTractName[i] >= 97 && strConsTractName[i] <= 122)			//97 ��Сдa ��122��Сдz
			{
				//	|| cConstraction[i] >= 65 && cConstraction[i] <= 90)			//65�Ǵ�дA �� 90�Ǵ�дZ
				strConsTractName[i] -= 32;											//Сд��ĸת��д��ĸ��
			}
		}
		strConsTractName = strConsTractName.substr(0, i);		//���ַ���0λ�ÿ�ʼ����ȡ�����ֵ��ڻ���Լ����

		//��ȡ�ڻ�ƽ��ӯ�����
		it = vWord.begin() + iTickByTickClosdProfits;
		if (*it == "--")
			fTickByTickClosdProfits = 0;
		else
			fTickByTickClosdProfits = stof(it->c_str());

		//��Ӳ�����
		fTemp = 0;

		//�Ȳ�����û������Ʒ�ֵĽ��׼�¼
		pairTemp.first = strInvestorID;
		pairTemp.second = strConsTractName;
		mapIt = mapArr.find(pairTemp);
		if (mapIt != mapArr.end())
		{
			//����Ѿ������Ʒ�֣�ֻ��Ҫ�����Ʒ�ֵ����ӯ���ϼӼ�����ӯ��
			//��ȡtuple��floatԪ��
			fTemp = mapIt->second.first;
			fTemp += fTickByTickClosdProfits;
			mapIt->second.first = fTemp;
		}
		else
		{
			//���û�����Ʒ�֣��¿�һ��Ʒ�ֺ�ӯ��
			mapArr.insert(make_pair(pairTemp, make_pair(fTickByTickClosdProfits, strFileTemp)));
		}
		strInverstorIDTotal = *vWord.begin();				//��¼��һ�е�Ͷ�����˻�
	}

	cout << strFileTemp << " �ļ���ȡ��ϣ� " << endl;
	fileCSV.close();

	// return (ElasticityResaultToTXT(mapArr, strFileName, "ƽ��ӯ�����.txt"));
	return mapArr;
}



// �����Ȩ ����������
void Notification()
{
	cout << "\n************************************************************" << endl << endl
		<< " �����Ϊ��ӯ���Գ��򣬴��뿪Դ��������Ȩ������Apache Lience\\BSD�淶������ѧϰ�ο���" << endl
		<< " ������Ա Sam Smith ��" << endl
		<< " email :sam-nuaa@nuaa.edu.cn" << endl
		<< " github�ֿ⣺https://github.com/SamSmithchina/qingsuan.git" << endl << endl
		<< " ʹ��˵����" << endl
		<< " 1.����Ա�����������н���ʵʱ�ֲ֡������ɽ����ܡ������ļ����������أ�" << endl
		<< "   �ļ���Ϊ ����+ʱ��+���.scv" << endl
		<< "   ��ʽ�硰ʵʱ�ֲ�_2024_05_25-15_28_60.csv��," << endl
		<< "         ���ɽ�����_2024_05_25-15_28_46.csv��" << endl
		<< " 2.�����ļ�������߿��������ս�����.exe������Ŀ¼�£�" << endl
		<< " 3.������ս�����.exe������" << endl
		<< " 4.����ֻ������������ļ����붨������������ļ���" << endl
		<< " 5.������ݡ�ʵʱ�ֲ֡����ġ�����ӯ���������ɽ����ܡ����ġ�ƽ�����ӯ�������Զ�������㣬�밴������󰴻س���ȷ�ϣ��˳�����" << endl
		<< " 6.Ŀ¼��������������ƽ��ӯ����ʺ͸���ӯ��.txt����" << endl << endl
		<< " 7.�������������쳣����رճ��򣬹ر�����ļ���Ȼ����������" << endl << endl
		<< "************************************************************" << endl
		<< endl << endl << endl << endl << endl;

	long   hFile = 0;				// �ļ����
	struct _finddata_t fileinfo;	//�ļ���Ϣ
	hFile = _findfirst("�ս����� ʹ��˵��.txt", &fileinfo);
	if (hFile == -1)				//������ʹ��˵���ļ�
	{
		ofstream of("�ս����� ʹ��˵��.txt");
		if (of.is_open())
		{
			cout << "�������������쳣����رճ��򣬹ر�����ļ���Ȼ����������" << endl;
			cout << "Notification error" << endl;
		}

		of << "\n************************************************************" << endl << endl
			<< " �����Ϊ��ӯ���Գ��򣬴��뿪Դ��������Ȩ������Apache Lience\\BSD�淶������ѧϰ�ο���" << endl
			<< " ������Ա Sam Smith ��" << endl
			<< " email :sam-nuaa@nuaa.edu.cn" << endl
			<< " github�ֿ⣺https://github.com/SamSmithchina/qingsuan.git" << endl << endl
			<< " ʹ��˵����" << endl
			<< " 1.����Ա�����������н���ʵʱ�ֲ֡������ɽ����ܡ������ļ����������أ�" << endl
			<< "   �ļ���Ϊ ����+ʱ��+���.scv" << endl
			<< "   ��ʽ�硰ʵʱ�ֲ�_2024_05_25-15_28_60.csv��," << endl
			<< "         ���ɽ�����_2024_05_25-15_28_46.csv��" << endl
			<< " 2.�����ļ�������߿��������ս�����.exe������Ŀ¼�£�" << endl
			<< " 3.������ս�����.exe������" << endl
			<< " 4.����ֻ������������ļ����붨������������ļ���" << endl
			<< " 5.������ݡ�ʵʱ�ֲ֡����ġ�����ӯ���������ɽ����ܡ����ġ�ƽ�����ӯ�������Զ�������㣬�밴������󰴻س���ȷ�ϣ��˳�����" << endl
			<< " 6.Ŀ¼��������������ƽ��ӯ����ʺ͸���ӯ��.txt����" << endl << endl
			<< " 7.�������������쳣����رճ��򣬹ر�����ļ���Ȼ����������" << endl << endl
			<< "************************************************************" << endl;
		of.close();
	}
}



#endif // !1
