
#include <Header.h>
#include <windows.h>
using namespace std;

int main()
{
	int iFlag = 0;

	string strFileName;
	string strFile;
	vector<string> vecFile;
	vector<string>::iterator it;
	ofstream ofFile;

	Notification();			//ʹ��˵��

	//ofFile.open("�ֲָ���ӯ��.txt", ios::trunc);				//�����ԭ�еļ�¼
	//ofFile.close();
	//vector<HOLDING> Holding;
	//strFileName = "ʵʱ�ֲ�";
	//vecFile = SearchCSVFile(strFileName);						//��ȡ�ֲֻ����ļ�����	
	//for (it = vecFile.begin(); it != vecFile.end(); it++)
	//{
	//	cout << endl << endl
	//		<< "************************************************************" << endl;
	//	strFile = *it;
	//	Holding.clear();
	//	iFlag = HlodingCSVFileRead(Holding, strFile);			//��ȡ�ֲֻ����ļ�
	//	if (iFlag == -1)
	//	{
	//		cout << "HlodingCSVFileRead error!" << endl;
	//		break;
	//	}
	//	iFlag = HoldingProfitsFloating(Holding,strFile);
	//	if (iFlag == -1)
	//	{
	//		cout << "HoldingProfitsFloating error" << endl;
	//		break;
	//	}
	//}

	//ofFile.open("ƽ��ӯ�����.txt", ios::trunc);				//�����ԭ�еļ�¼
	//ofFile.close();
	//vector<TRANSACTION> Trans;
	//strFileName = "�ɽ�����";
	//vecFile = SearchCSVFile(strFileName);						//��ȡ�ɽ������ļ���							
	//for (it = vecFile.begin(); it != vecFile.end(); it++)
	//{
	//	cout << endl << endl
	//		<< "************************************************************" << endl;
	//	strFile = *it;
	//	Trans.clear();
	//	//Trans.erase();
	//	iFlag = TransactionCSVFileRead(Trans, strFile);			//��ȡ�ɽ������ļ���ȡ������
	//	if (iFlag == -1)
	//	{
	//		cout << "TransactionCSVFileRead error!" << endl;
	//		break;
	//	}
	//	iFlag = TickByTickTransactionProfits(Trans, strFile);	//�ɽ�ӯ�����
	//	if (iFlag == -1)
	//	{
	//		cout << "TickByTickTransactionProfits error!" << endl;
	//		break;
	//	}
	//}

	//�����¼������map
	map<pair<string, string>, pair<float, string>> mapTranscation;
	map<pair<string, string>, pair<float, string>> mapHolding;
	//map<pair<string, string>, pair<float, string>>::iterator itMapTranscation;

	ofFile.open("ƽ��ӯ����ʺ͸���ӯ��.txt", ios::trunc);				//�����ԭ�еļ�¼
	ofFile.close();

	//����ɽ�����
	strFileName = "�ɽ�����";
	vecFile = SearchCSVFile(strFileName);						//��ȡ�ɽ������ļ���	
	for (it = vecFile.begin(); it != vecFile.end(); it++)
	{
		strFile = *it;
		ElasticityTransactionCSVFileRead(mapTranscation, strFile);			//��ȡ�ɽ������ļ���ȡ������
	}

	//���� ʵʱ�ֲ�
	vecFile = SearchCSVFile("ʵʱ�ֲ�");
	for (it = vecFile.begin(); it != vecFile.end(); it++)
	{
		strFile = *it;
		ElasticityHoldingCSVFileRead(mapHolding, strFile);
	}

	//��ʾ�����д���ļ�
	//ElasticityResaultToTXT(mapTranscation, "ƽ��ӯ�����.txt");
	//ElasticityResaultToTXT(mapHoding, "����ӯ��.txt");
	map<pair< string, string >, pair< float, float >> mergeMap = MergeMap(mapTranscation, mapHolding);
	ElasticityTotalResaultToTXT(mergeMap, "ƽ��ӯ����ʺ͸���ӯ��.txt");

	cout << "��������󰴻س���ȷ�ϣ��������� " << endl;
	getchar();
	return 0;
}