
#include <Header.h>
#include <windows.h>
using namespace std;

int main()
{
	int iFlag = 0;

	string strFileName ;
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

	ofFile.open("ƽ��ӯ�����.txt", ios::trunc);				//�����ԭ�еļ�¼
	ofFile.close();
	vector<TRANSACTION> Trans;
	strFileName = "�ɽ�����";
	vecFile = SearchCSVFile(strFileName);						//��ȡ�ɽ������ļ���							
	for (it = vecFile.begin(); it != vecFile.end(); it++)
	{
		cout << endl << endl
			<< "************************************************************" << endl;
		strFile = *it;
		Trans.clear();
		//Trans.erase();
		iFlag = TransactionCSVFileRead(Trans, strFile);			//��ȡ�ɽ������ļ���ȡ������
		if (iFlag == -1)
		{
			cout << "TransactionCSVFileRead error!" << endl;
			break;
		}
		iFlag = TickByTickTransactionProfits(Trans, strFile);	//�ɽ�ӯ�����
		if (iFlag == -1)
		{
			cout << "TickByTickTransactionProfits error!" << endl;
			break;
		}
	}

	//cout << "  -------------------------------" << endl
	//cout  << "\n10�������Զ��ر�" << endl;
	//Sleep(10000);
	cout << "��������������� " << endl;
	getchar();
	return 0;
}