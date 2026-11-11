#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010];
int maxn;
bool check(int l,int r){
	long long s1=a[r]*r-s[r],s2=a[r]*(l-1)-s[l-1];
	long long d=s1-s2;
	return d<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n,ans=0;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(check(i,mid)){
				l=mid+1;
				ans=mid;	
			}
			else r=mid-1;
		}
		maxn=max(maxn,ans-i+1);
	}
	cout<<maxn;
	return 0;
}
