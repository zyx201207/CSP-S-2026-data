#include<bits/stdc++.h>
using namespace std;
long long n,m,a,t[200002][35],k[35],ans,s,maxn;
bool vis[2000002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		while(a!=0){
			t[i][++k[i]]=a%2;
			a/=2;
		}
		maxn=max(maxn,k[i]);
	}
	ans=0;
	for(int i=maxn;i>=1;i--){
		s=0;
		for(int j=1;j<=n;j++)if(!vis[j]&&t[j][i])s++;
		if(s>=m){
			ans=ans|(1<<(i-1));
			for(int j=1;j<=n;j++)if(t[j][i]==0)vis[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
