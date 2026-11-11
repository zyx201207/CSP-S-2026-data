#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],a1[10000],d[10000],cnt,ma;
//初二第一次来S组说是('_')
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//打个暴力就跑路吧，力竭了(;-;)
//其实暴力也不会打(太菜了）  
// 事已至此 
//na yi tian de you yu you yu qi lai
//na yi tian de ji mo ji mo qi lai 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<i;j++){
			cnt+=a1[j];
			if(cnt<=m){
				d[i]=max(d[j-1],d[j-1]+a1[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		ma=max(d[i],ma);
	}
	cout<<ma; 
//万一能对一个点呢(TwT)
	return 0;
}

