#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);

	long long  m,n,cr[10010],cishu,lry[10010],jkx[10010];
	cin>>n>>m;
	cr[0]=0;
	for(int i=1;i<=n;i++){
		cin>>cr[i];
	} 
	for(int j=0;j<=n-1;j++){
		lry[j]=cr[j]; 
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=n-i;j++){
			lry[j]=cr[j];
		}
	}
	for(int i=1;i<=n-1;i++){
		jkx[i]=lry[i]+cr[i];
	}
	cout<<m*2-1; 
	return 0;
}