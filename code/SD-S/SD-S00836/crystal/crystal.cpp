#include<bits/stdc++.h>
using namespace std;
int e[500001],n,m,cha[50001],flag,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>e[i];
	}
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			cha[i]+=e[i]-e[j];
		}
	}
	for(int i=1;i<=n;i++){
		flag=cha[i];
		for(int j=1;j<i;j++){
			if(flag<=m) ans=max(ans,i-j+1);
			flag=flag+e[j]-e[i];
		}
	}
	cout<<ans;
	return 0;
}
