#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7;
long long  a[maxn];
bool cmp(long long  a,long long  b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,minn=1e9,maxns=-1e9;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	    if(maxns<a[i]) maxns=a[i];
	    if(minn>a[i]) minn=a[i];
	}
	sort(a,a+n,cmp);
	int ans=0;
	for(int k=minn;k<=maxns;k++){
		int cnt=0,num=0;
		for(int i=0;i<=n;i++){
			if(cnt+k-a[i]<=m && a[i]<k){
			cnt+=k-a[i];
			num++;
	        }
		}
		ans=max(ans,num);
	}
	cout<<ans+1;
}
