#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,a[N],anss;
ll m,sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans;
		while(l<=r){
			int mid=l+r>>1;
			if(1ll*a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)ans=mid,r=mid-1;
			else l=mid+1;
		}
		anss=max(anss,i-ans+1);
	}
	cout<<anss;
	return 0;
}/*
CCF,I love you.
I AC T1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
CCF,you are my father

14:37: I got 100pts
*/