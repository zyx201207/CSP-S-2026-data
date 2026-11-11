#include<bits/stdc++.h>
using namespace std;
long long m,a[500010],d[500010],sum=0;
int n,maxn=1;//暴力 
int main(){//注意楼下的注释 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
if(n==1){
	cout<<1<<'\n';
}
else{
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){//小心边界值 
		d[i]=a[i]-a[i-1];//差值  
	}
	for(int i=1;i<=n;i++){//小心边界值 
		sum=0;
		for(int j=i;j<=n;j++){
			sum+=d[j]*(j-i+1);
			if(sum<=m&&maxn<j-i+1){
				maxn=j-i+1;
			}
			else if(sum>m) break;
		}
	}
	cout<<maxn+1<<'\n';
}
	return 0;
}
