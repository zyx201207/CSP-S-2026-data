#include<bits/stdc++.h>
using namespace std;
long long T[100005];
long long sline[505][100005];
long long slinet[505][100005];
long long k[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>T[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>sline[i][j]>>slinet[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		long long b,e,t=0;
		cin>>b>>e;
		long long bmt=99999,emt=99999;
  	for(int x=1;x<=n;x++){
		for(long long j=1;j<=k[x];j++){
			if(sline[x][j]==b&&slinet[x][j]<=bmt)bmt=slinet[x][j];
			else if(sline[x][j]==e&&slinet[x][j]<=emt)emt=slinet[x][j];
		}
	}t=T[b]+T[e]+bmt+emt;
	cout<<t<<"\n";
 }
	return 0;
}