#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y){
	return x<=y;
}
int n,m,a[500010],cha[500010],sum[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cha[i-1]=a[i]-a[i-1]; 
	}
	bool flag=1;
	for(int i=1;i<n;++i){
		if(cha[i]!=0){flag=0;break;}
	}
	if(flag==1){
		cout<<n;
		return 0;
	}
	flag=1;
	int A=cha[1];
	for(int i=1;i<=n;++i){
		if(cha[i]!=A) flag=0;
	}
	if(flag==1){
		int t=n/A;
		for(int i=1;i<=1000;++i){
			if((i*(i+1)+1)/2>t){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;++i){
		sum[i]=a[i]+sum[i-1]; 
	}
	for(int i=2;i<=n;++i){
		int minn=1e18;
		for(int j=1;j<=n-i+1;++j){
			minn=min(minn,a[j+i-1]*(i-1)-sum[j+i-2]+sum[j-2]); 
		}
		if(minn>m){
			cout<<i-1;
			return 0;
		}else if(minn==m){
			cout<<i;
			return 0;
		}
	}
} 
