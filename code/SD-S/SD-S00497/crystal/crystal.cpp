#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans[N];
int maxx;
int fa=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			fa=0;
			break;
		}
	}
	if(fa==1){
		for(int i=2;i<=n;i++){
			int sum=((1+i)*i)/2;
			if(m<sum){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int x=m,f=0;
		for(int j=i-1;j>=1;j--){
			int gap=a[i]-a[j];
			x-=gap;
			if(x<0){
				f=1;
				ans[i]=i-j;
				break;
			}
		}
		if(f==0){
			ans[i]=i;
		}
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,ans[i]);
	}
	cout<<maxx;
	return 0;
}
