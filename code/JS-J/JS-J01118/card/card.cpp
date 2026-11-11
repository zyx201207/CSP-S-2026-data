#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=2e5+7;
int a[N],f[N],ct[N],x[N],ans[N];
vector<int> vc[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	bool tsA=1;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>a[i-1]) tsA=0;
		f[a[i]]=i;
		vc[i].reserve(m+2);
	}
	if(tsA){
		for(int i=1;i<=m;++i) cout<<f[i]<<" ";
		return 0;
	}
	vc[n+1].reserve(m+1);
	for(int i=1;i<=m;++i) x[f[i]]=N;
	for(int i=n;i>=1;--i){
		if(x[i]==N) ct[i]=ct[i+1]+1;
		else ct[i]=ct[f[a[i]]];
		if(x[i]==N){
			for(int j=0;j<ct[i+1];++j)
				vc[i][j]=vc[i+1][j],ans[vc[i][j]]++;
			vc[i][ct[i+1]]=a[i];
			ans[a[i]]++;
		}
		else{
			for(int j=0;j<ct[f[a[i]]];++j)
				vc[i][j]=vc[f[a[i]]][j],ans[vc[i][j]]++;
		}
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	return 0;
}
