#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define endl "\n"
struct Station{
	int ID;
	int LengthDtoH;
	map<int,int> Platforms;
	vector<int> PassedLine;
	int LengthLtoL(int LineA,int LineB){
		return Platforms[LineA]+Platforms[LineB];
	}
	bool Visited=false;
}a[509];
struct Line{
	int ID;
	vector<int> PassedStation;
}Lines[500009];
int c,n,m,d,p;
int Begin,End;
int Ans=INT_MAX;
void dfs(int StationNow,int LineFrom,int TimeSpend){
	if(a[StationNow].Visited)return;
	if(StationNow==End){
		Ans=min(Ans,TimeSpend+a[StationNow].LengthDtoH);
		return;
	}
	a[StationNow].Visited=true;
	for(int i=0;i<a[StationNow].PassedLine.size();i++){
		if(a[StationNow].PassedLine[i]==LineFrom)continue;
		for(int j=0;j<=Lines[a[StationNow].PassedLine[i]].PassedStation.size();j++){
			dfs(Lines[a[StationNow].PassedLine[i]].PassedStation[j],a[StationNow].PassedLine[i],TimeSpend+a[StationNow].LengthLtoL(LineFrom,a[StationNow].PassedLine[i]));
		}
	}
	a[StationNow].Visited=false;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i].LengthDtoH;
		a[i].ID=i;
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		Lines[i].ID=i;
		while(k--){
			int s,p;
			cin>>s>>p;
			a[s].Platforms[i]=p;
			a[s].PassedLine.push_back(i);
			Lines[i].PassedStation.push_back(s);
		}
	}
	while(p--){
		cin>>Begin>>End;
		for(int i=0;i<a[Begin].PassedLine.size();i++){
			dfs(Begin,a[Begin].PassedLine[i],a[Begin].LengthDtoH);
		}
		cout<<Ans<<endl;
	}
	return 0;
}
