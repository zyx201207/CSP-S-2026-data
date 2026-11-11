#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,Cry[500010],V[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>Cry[i];
	sort(Cry+1,Cry+n+1);
	for(int i=2;i<=n;i++){
		V[i]=V[i-1]+(Cry[i]-Cry[i-1])*(i-1);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((V[j]-V[i])<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
