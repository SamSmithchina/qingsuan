
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

	//ofFile.open("平仓盈亏逐笔.txt", ios::trunc);				//先清空原有的记录
	//ofFile.close();
	//vector<TRANSACTION> Trans;
	//strFileName = "成交汇总";
	//vecFile = SearchCSVFile(strFileName);						//获取成交汇总文件名							
	//for (it = vecFile.begin(); it != vecFile.end(); it++)
	//{
	//	cout << endl << endl
	//		<< "************************************************************" << endl;
	//	strFile = *it;
	//	Trans.clear();
	//	//Trans.erase();
	//	iFlag = TransactionCSVFileRead(Trans, strFile);			//读取成交汇总文件，取得数组
	//	if (iFlag == -1)
	//	{
	//		cout << "TransactionCSVFileRead error!" << endl;
	//		break;
	//	}
	//	iFlag = TickByTickTransactionProfits(Trans, strFile);	//成交盈亏逐笔
	//	if (iFlag == -1)
	//	{
	//		cout << "TickByTickTransactionProfits error!" << endl;
	//		break;
	//	}
	//}

	//定义记录处理结果map
	map<pair<string, string>, pair<float, string>> mapTranscation;
	map<pair<string, string>, pair<float, string>> mapHolding;
	//map<pair<string, string>, pair<float, string>>::iterator itMapTranscation;

	ofFile.open("平仓盈亏逐笔和浮动盈亏.txt", ios::trunc);				//先清空原有的记录
	ofFile.close();

	//处理成交汇总
	strFileName = "成交汇总";
	vecFile = SearchCSVFile(strFileName);						//获取成交汇总文件名	
	for (it = vecFile.begin(); it != vecFile.end(); it++)
	{
		strFile = *it;
		ElasticityTransactionCSVFileRead(mapTranscation, strFile);			//读取成交汇总文件，取得数组
	}

	//处理 实时持仓
	vecFile = SearchCSVFile("实时持仓");
	for (it = vecFile.begin(); it != vecFile.end(); it++)
	{
		strFile = *it;
		ElasticityHoldingCSVFileRead(mapHolding, strFile);
	}

	//显示结果并写入文件
	//ElasticityResaultToTXT(mapTranscation, "平仓盈亏逐笔.txt");
	//ElasticityResaultToTXT(mapHoding, "浮动盈亏.txt");
	map<pair< string, string >, pair< float, float >> mergeMap = MergeMap(mapTranscation, mapHolding);
	ElasticityTotalResaultToTXT(mergeMap, "平仓盈亏逐笔和浮动盈亏.txt");

	cout << "按任意键后按回车键确认，结束程序 " << endl;
	getchar();
	return 0;
}