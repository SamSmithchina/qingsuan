// ����˵��:
// ������Ϊ�������Աÿ���̺�����ӯ������ʹ�á�
// *******
// 
// �뽻��Ա�������������ĳֲֺͳɽ����ݺ󣬽������ļ������ڱ�����ͬһ���ļ����С�
// 
// *******
// ������־��202-5-22  
//			 �����ڻ�Ʒ������;�˶�ƽ��ӯ����ʵ�ͳ�Ʒ���
// ������־��202 - 3 - 21
// 
// ���򽫻��ȡ�������ݣ��Զ�����ȫ��Ʒ�֡�ȫ����Լ�ĳֲ�ӯ����ɽ����ӯ����
// ���ǽ������ĳ��ڽ���Ʒ�ָ��»�����δ���Ľ���Ʒ�ִ��벻ȷ�����������н���Ʒ��ʶ��ƥ�书�ܡ�ÿ����Լ�����Զ����ֲ�ʶ��
// ������֡�M2305��ʶ��Ϊ��M��Ʒ�֣���M2305P3800��ʶ��Ϊ��M��Ʒ���¡�P3800����
// ������֡�MK305����ʶ��Ϊ��MK��Ʒ�֣� ��MK305C5800��ʶ��Ϊ��MK��Ʒ��"C5800"��
// 
// ������Ϊ��ӯ���Գ��򣬴��뿪Դ��������Ȩ������Apache Lience\BSD�淶������ѧϰ�ο���
// ������Ա Sam Smith ��
// email :sam-nuaa@nuaa.edu.cn
// ʹ��˵����
// 1.����Ա�����������н���ʵʱ�ֲ֡������ɽ����ܡ������ļ����������أ�
//   �ļ���Ϊ ����+ʱ��+���.scv
//   ��ʽ�硰ʵʱ�ֲ�_2024_05_25-15_28_60.csv��,
//         ���ɽ�����_2024_05_25-15_28_46.csv��
// 2.�����ļ�������߿��������ս�����.exe������Ŀ¼�£�
// 3.������ս�����.exe������
// 4.����ֻ������������ļ����붨������������ļ���
// 5.������ݡ��ֲָ���ӯ��������ƽ�����ӯ�������Զ�������㣬�밴������˳�����
// 6.Ŀ¼���������������ֲָ���ӯ��.txt������ƽ�����ӯ��.txt����




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

	//����Ԫ���ڱ������Ϊ��--������0����ʾ�������ݵ������ݱ�ʾ
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
	string strTempDir = cwd;		//ִ�г���ǰ·����
	strTempDir.append("\\*");

	const string strFileType = ".csv";	//ָ���ļ�����
	long   hFile = 0;				// �ļ����
	vector<string> vecFiles;		//�洢���ϵ��ļ���
	struct _finddata_t fileinfo;	//�ļ���Ϣ
	string strTime;
	string strTempFile;
	string strPath;

	hFile = _findfirst(strTempDir.c_str(), &fileinfo);
	if (hFile != -1) //�����ļ�
	{
		do {
			strTempFile = fileinfo.name;
			strTime = GetTime();				//�ļ����ָ�ʽ�硰ʵʱ�ֲ�_2023_03_21-15_28_49.csv��
			if (strTempFile.find(strFile) != string::npos			//���ؼ��ֺ�csv��ʽѰ���ļ�
				&& strTempFile.find(strTime) != string::npos
				&& strTempFile.find(strFileType) != string::npos)
			{
				strPath = cwd;
				vecFiles.push_back(strPath.append("\\").append(strTempFile));
			}


		} while (_findnext(hFile, &fileinfo) == 0);  //Ѱ����һ�����ɹ�����0������-1
		_findclose(hFile);		//close
	}

	if (vecFiles.size() == 0)		//û���ļ�
	{
		std::cout << "SearchCSVFile() û���ҵ� "
			<< strFile << "_" << strTime << strFileType
			<< " �ļ�" << endl;
	}
	else
	{
		for (int i = 0; i < (int)vecFiles.size(); i++)
		{
			cout << "�ҵ��ļ� " << vecFiles[i] << endl;
		}
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


//���룺map<string,float> �ṹ��<Ʒ��,���ӯ��>�� 
//      �˻�Ψһ�˺� strInvestorID,Դ�ļ� strFile ����������ļ�strResultFile��
//      ������д��ָ���ļ�ƽ��ӯ�����.txt
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

	bool bFlag = false;
	const string str1 = "---------------------------------";
	const string str2 = "                                 ";
	map<string, float>::iterator mapIt = mapArr.begin();
	string strTemp = strFile.substr(strFile.rfind('\\') + 1, strFile.npos);
	of << strTemp << "  ͳ�����£�" << endl;
	of << endl << "�˺�   " << strInvestorID << endl
		<< "|" << str1 << "|" << endl
		<< "|" << str2 << "|" << endl;
	cout << endl << "�˺�   " << strInvestorID << endl
		<< "|" << str1 << "|" << endl
		<< "|" << str2 << "|" << endl;

	while (mapIt != mapArr.end())
	{
		//�̶����������ʽ
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
	map<string ,float>::iterator mapIt;
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




// �����Ȩ ����������
void Notification()
{
	cout << "************************************************************" << endl
		<< " ������Ϊ��ӯ���Գ��򣬴��뿪Դ��������Ȩ������Apache Lience\\BSD�淶������ѧϰ�ο���" << endl
		<< " ������Ա Sam Smith ��" << endl
		<< " email :sam-nuaa@nuaa.edu.cn" << endl
		<< " ʹ��˵����" << endl
		<< " 1.����Ա�����������н���ʵʱ�ֲ֡������ɽ����ܡ������ļ����������أ�" << endl
		<< "   �ļ���Ϊ ����+ʱ��+���.scv" << endl
		<< "   ��ʽ�硰ʵʱ�ֲ�_2024_05_25-15_28_60.csv��," << endl
		<< "         ���ɽ�����_2024_05_25-15_28_46.csv��" << endl
		<< " 2.�����ļ�������߿��������ս�����.exe������Ŀ¼�£�" << endl
		<< " 3.������ս�����.exe������" << endl
		<< " 4.����ֻ������������ļ����붨������������ļ���" << endl
		<< " 5.������ݡ��ֲָ���ӯ��������ƽ�����ӯ�������Զ�������㣬�밴������˳�����" << endl
		<< " 6.Ŀ¼���������������ֲָ���ӯ��.txt������ƽ�����ӯ��.txt����" << endl << endl
		<< "   �������������쳣����رճ��򣬹ر�����ļ���Ȼ����������" << endl
		<< endl << endl << endl << endl << endl;

	long   hFile = 0;				// �ļ����
	struct _finddata_t fileinfo;	//�ļ���Ϣ
	hFile = _findfirst("�ս����� ʹ��˵��.txt", &fileinfo);
	if (hFile == -1)				//������ʹ��˵���ļ�
	{
		ofstream of("�ս����� ʹ��˵��.txt" );
		if (of.is_open())
		{
			cout << "�������������쳣����رճ��򣬹ر�����ļ���Ȼ����������" << endl;
			cout << "Notification error" << endl;
		}

		of << "************************************************************" << endl
			<< " ������Ϊ��ӯ���Գ��򣬴��뿪Դ��������Ȩ������Apache Lience\\BSD�淶������ѧϰ�ο���" << endl
			<< " ������Ա Sam Smith ��" << endl
			<< " email :sam-nuaa@nuaa.edu.cn" << endl
			<< " ʹ��˵����" << endl
			<< " 1.����Ա�����������н���ʵʱ�ֲ֡������ɽ����ܡ������ļ����������أ�" << endl
			<< "   �ļ���Ϊ ����+ʱ��+���.scv" << endl
			<< "   ��ʽ�硰ʵʱ�ֲ�_2024_05_25-15_28_60.csv��," << endl
			<< "         ���ɽ�����_2024_05_25-15_28_46.csv��" << endl
			<< " 2.�����ļ�������߿��������ս�����.exe������Ŀ¼�£�" << endl
			<< " 3.������ս�����.exe������" << endl
			<< " 4.����ֻ������������ļ����붨������������ļ���" << endl
			<< " 5.������ݡ��ֲָ���ӯ��������ƽ�����ӯ�������Զ�������㣬�밴������˳�����" << endl
			<< " 6.Ŀ¼���������������ֲָ���ӯ��.txt������ƽ�����ӯ��.txt����" << endl << endl
			<< "   �������������쳣����رճ��򣬹ر�����ļ���Ȼ����������" << endl;
		of.close();
	}
}



#endif // !1