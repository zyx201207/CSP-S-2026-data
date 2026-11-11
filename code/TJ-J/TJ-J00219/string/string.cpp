#include<bits/stdc++.h>
using namespace std;
int n;
struct Spilt{
	char L;
	int D;
}Head[200009],Back[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	long long tot=0;
	for(int i=1;i<=n;i++){
		char c;
		int e;
		cin>>e>>c;
		Head[i].D=tot;
		Head[i].L=c;
		tot+=e;
		Back[n-i+1].D=tot;
		Back[n-i+1].L=c;
	}
	const long long Halftot=(tot+1)/2;
	int Headtot=0,Backtot=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(Head[i].D>Halftot);
		while(Back[Backtot].D<Head[i].D){
			if(Back[Backtot].L!=Head[i].L)ans+=max(tot-Back[Backtot].D,(long long)Head[i].D)-min(tot-Back[Backtot].D,(long long)Head[i].D);
			if(tot-Back[Backtot].D<=Head[i].D)Backtot++;
		}
	}
	cout<<ans;
	return 0;
}
