#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e5+5;
int n,m,a[N],hj[N],qwz[M];
long long f[N],ans[M];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
		if(qwz[a[i]]>0) hj[qwz[a[i]]]=i;
		qwz[a[i]]=i;
		hj[i]=i+1;
		f[i]=1;
	}
	for(int i=1; i<=n; i++){
		f[hj[i]]+=f[i];
	}
	for(int i=1; i<=n; i++){
		if(hj[i]==i+1 && a[i+1]!=a[i]) ans[a[i]]=f[i];
	}
	for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
	return 0;
}
