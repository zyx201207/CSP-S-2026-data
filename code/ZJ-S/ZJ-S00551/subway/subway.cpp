#include<bits/stdc++.h>
using namespace std;

int TestNum;//c, 0<=c<=25;
int MetroCnt;//n, 1<=n<=500;
int StationCnt;//m, 1<=m<=5*10^5;
int LinePerStation;//d, 1<=d<=20;
int Plans;//q, 1<=q<=10^5;
long long GroundToStation[500002];//max 1e9;
vector<pair<int,long long> > StationToLine[500002];//max 1e9; 
long long XtoY[502][502];//max 1e18;
//long long Floyd[502][502][502];//max 1e18;
const long long Infinity=1e17;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>TestNum>>MetroCnt>>StationCnt>>LinePerStation>>Plans;
	for(int i=1;i<=StationCnt;++i){
		cin>>GroundToStation[i];
	}
	for(int i=1;i<=MetroCnt;++i){//i:Metro no_.
		int StationsInIt;
		cin>>StationsInIt;
		for(int j=1;j<=StationsInIt;++j){
			int StationNum;
			long long STLtime;//Station to line
			cin>>StationNum>>STLtime;
			StationToLine[StationNum].push_back(pair<int,long long>(i,STLtime));
		}
	}
	for(int i=1;i<=MetroCnt;++i){
		for(int j=1;j<=MetroCnt;++j){
			if(i==j){
				XtoY[i][j]=0;
//				for(int k=1;k<=MetroCnt;++k){
//					Floyd[i][j][k]=0;
//				}
			}else{
				XtoY[i][j]=Infinity;
//				for(int k=1;k<=MetroCnt;++k){
//					Floyd[i][j][k]=Infinity;
//				}
			}
		}
	}
	for(int i=1;i<=StationCnt;++i){
		int InLoopLnCnt=StationToLine[i].size();//The count of lines in the station.
		for(int Start=0;Start<InLoopLnCnt;++Start){
			int SCnt=StationToLine[i][Start].first;
			long long STime=StationToLine[i][Start].second;
			for(int End=Start+1;End<InLoopLnCnt;++End){
				int ECnt=StationToLine[i][End].first;
				long long ETime=StationToLine[i][End].second;
				XtoY[SCnt][ECnt]=min(XtoY[SCnt][ECnt],STime+ETime);
				XtoY[ECnt][SCnt]=min(XtoY[ECnt][SCnt],STime+ETime);
			}
		}
	}
//	cout<<clock()<<endl;
//	for(int i=1;i<=MetroCnt;++i){
//		for(int j=1;j<=MetroCnt;++j){
//			if(XtoY[i][j]!=Infinity)
//			for(int k=1;k<=MetroCnt;++k){
//				Floyd[i][j][k]=XtoY[i][j];
//			}
//		}
//	}
	for(int k=1;k<=MetroCnt;++k){
		for(int i=1;i<=MetroCnt;++i){
			for(int j=1;j<=MetroCnt;++j){
//				Floyd[i][j][k]=min(Floyd[i][j][k],XtoY[i][k]+XtoY[k][j]);
				XtoY[i][j]=min(XtoY[i][j],XtoY[i][k]+XtoY[k][j]);
			}
		}
	}
	for(int i=1;i<=Plans;++i){
		int StartStation,EndStation;
		cin>>StartStation>>EndStation;
		long long GrToSt=GroundToStation[StartStation]+GroundToStation[EndStation];
		long long StToPl=Infinity;
		int StLines=StationToLine[StartStation].size();
		int EdLines=StationToLine[EndStation].size();
		for(int i=0;i<StLines;++i){
			int TheSLine=StationToLine[StartStation][i].first;
			long long StartSTP=StationToLine[StartStation][i].second;//The time spent in the start station from Station to Platform
			for(int j=0;j<EdLines;++j){
				int TheELine=StationToLine[EndStation][j].first;
				long long EndSTP=StationToLine[EndStation][j].second;//The time spent in the end station from Station to Platform
				StToPl=min(StToPl,XtoY[TheSLine][TheELine]+StartSTP+EndSTP);
				}
		}
		cout<<StToPl+GrToSt<<endl;
	}
	return 0;
}
