
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

	Notification();			//使用说明

	//ofFile.open("持仓浮动盈亏.txt", ios::trunc);				//先清空原有的记录
	//ofFile.close();
	//vector<HOLDING> Holding;
	//strFileName = "实时持仓";
	//vecFile = SearchCSVFile(strFileName);						//获取持仓汇总文件名字	
	//for (it = vecFile.begin(); it != vecFile.end(); it++)
	//{
	//	cout << endl << endl
	//		<< "************************************************************" << endl;
	//	strFile = *it;
	//	Holding.clear();
	//	iFlag = HlodingCSVFileRead(Holding, strFile);			//读取持仓汇总文件
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

	ofFile.open("平仓盈亏逐笔.txt", ios::trunc);				//先清空原有的记录
	ofFile.close();
	vector<TRANSACTION> Trans;
	strFileName = "成交汇总";
	vecFile = SearchCSVFile(strFileName);						//获取成交汇总文件名							
	for (it = vecFile.begin(); it != vecFile.end(); it++)
	{
		cout << endl << endl
			<< "************************************************************" << endl;
		strFile = *it;
		Trans.clear();
		//Trans.erase();
		iFlag = TransactionCSVFileRead(Trans, strFile);			//读取成交汇总文件，取得数组
		if (iFlag == -1)
		{
			cout << "TransactionCSVFileRead error!" << endl;
			break;
		}
		iFlag = TickByTickTransactionProfits(Trans, strFile);	//成交盈亏逐笔
		if (iFlag == -1)
		{
			cout << "TickByTickTransactionProfits error!" << endl;
			break;
		}
	}

	//cout << "  -------------------------------" << endl
	//cout  << "\n10秒后程序自动关闭" << endl;
	//Sleep(10000);
	cout << "按任意键结束程序 " << endl;
	getchar();
	return 0;
}