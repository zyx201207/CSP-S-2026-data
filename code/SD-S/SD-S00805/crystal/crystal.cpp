#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long m;
long long a[500005];
long long s[500005];
int ma=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
//				cerr<<"R"<<mid<<'\n';
				r=mid-1;
				ans=mid;
			}
			else{
//				cerr<<"L"<<mid<<'\n';
				l=mid+1;
			}
		}
		ma=max(ma,i-ans+1);
//		cerr<<i<<'\t'<<ma<<'\n';
	}
	cout<<ma<<'\n';
	return 0;
}
