#include<bits/stdc++.h>
#define int long long
#define fileio
//#define opensync
//#define multicase
using namespace std;
int c,t,n,k,u,v;
void INIT(){

}
void MAIN(int CASE){
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<n*(n-1)/2-(n-1)<<'\n';
	}
}
signed main(){
#ifndef opensync
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
#ifdef fileio
	ifstream fin("hub.in");
	ofstream fout("hub.out");
	auto oldcin=cin.rdbuf(fin.rdbuf());
	auto oldcout=cout.rdbuf(fout.rdbuf());
#endif
	int t=1;
#ifdef multicase
	cin>>t;
#endif
	INIT();
	for(int i=0;i<t;i++){
		MAIN(i);
	}
#ifdef fileio
	cin.rdbuf(oldcin);
	cout.rdbuf(oldcout);
#endif
	return 0;
}
/*
16:21
不行好慌啊现在
不对我在慌啥？
我不已经切了T1T2了？
今年的题是不是有点简单了？
我应该先去写T1T2的对拍。 

I'm luogu uid 1180206
love 720872
100+100+24+10
*/ 
