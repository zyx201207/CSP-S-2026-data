#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],maxn;
map<long long,int>mp;
bool bj=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&bj){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) bj=false;
		}
	}
	if(bj){
		int x=a[2]-a[1],t=m,ans=0;
		for(int i=1;i<=n;i++){
			if(t>=x*i){
				t-=(unsigned long long)(x*i);
				ans++;
			}else{
				break;
			}
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long t=m;
		int j=i-1;
		long long x=1;
		while(t>=a[i]-a[j]&&j>0){
			t-=a[i]-a[j];
			x++;
			j--;
		}
		maxn=max(maxn,x);
	} 
	cout<<maxn;
	return 0;
} 
