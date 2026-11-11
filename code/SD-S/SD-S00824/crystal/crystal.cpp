#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#define int long long
using namespace std;
const int MAXN=5e5+20;
int n,m,cnt=0;
int a[MAXN],maxn=-1e18,ans=0;
bool cmp(int x,int y){
	return x>y;
}
void check(int x){
	int t=m;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x&&x-a[i]<=t){
			t-=(x-a[i]);
	//		cout<<x<<" "<<a[i]<<" "<<t<<'\n';
			cnt++;
		}
		else if(a[i]<=x&&x-a[i]>t)break;
	}
	ans=max(ans,cnt);
}
void solve(){
	for(int i=1;i<=100;i++)check(i);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;int d=0;bool f=1,f1=1,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]!=i)f=0;
		if(f2)if(d!=a[i]-a[i-1])f1=0;
		if(i>1&&!f2){
			d=a[i]-a[i-1];
			f2=1;
		}
	}
	if(n<=5000){
		sort(a+1,a+n+1,cmp);
		int cans=0;
		for(int i=1;i<=n;i++){
			int cnt=0,t=m;
			for(int j=i;j<=n;j++){	
				if(a[j]<=a[i]&&a[i]-a[j]<=t){
					t-=(a[i]-a[j]);
					cnt++;
				}
				else if(a[j]>a[i]||(a[j]<=a[i]&&a[i]-a[j]>t))break;
			}
			cans=max(cans,cnt);
		}
		cout<<cans;
		return 0;
	}
	if(f){
		for(int i=1;i<=n;i++)
			if(m<(i-1)*i/2){
				cout<<i-1;
				return 0;
			}
	}
	if(f1){
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
			if(m<(i-1)*d+(i-1)*(i-2)*d/2){
				cout<<i-1;
				return 0;
			}
	}
	sort(a+1,a+n+1,cmp);
	solve();
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

6 8
1 2 3 4 5 6

8 11
2 4 6 8 10 12 14 16
*/
