#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],cha[50005][50005],ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cha[i][j]=(a[j]-a[i])*2-cha[i-1][j];
			if(cha[i][j]==m){
				ma=j-i;
			}
		}
	}
	cout<<ma<<endl;
	return 0;
}