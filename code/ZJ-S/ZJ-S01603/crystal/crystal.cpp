#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],ma=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+1+n);
	f[0]=0,f[1]=a[1];
	for(int i=2;i<=n;i++){
		f[i]=a[i]+f[i-1];
	}
	int sum=1,st=1;
	while(1){
		while((sum-st+1)*a[sum]-(f[sum]-f[st-1])<=m){
			ma=max(ma,sum-st+1);
			sum++;
			if(sum>n){
				cout<<ma;
				return 0;
			}
		}
		st++;	
	}
	return 0;
}
