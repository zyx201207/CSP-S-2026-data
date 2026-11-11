#include<bits/stdc++.h>
using namespace std;
int n,m,maxs=0;
long long a[500010];
bool check(int x){
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x) break;
		cnt++;
		ans+=(x-a[i]);
	}
	if(ans>m) return 0;
	else{
		if(cnt>maxs){
			maxs=cnt;
			return 1;
		}
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
    long long l=a[1],r=a[n],mid,cnt=0,ans=0;
	while(l<r){
		mid=(l+r)>>1; 
		if(check(mid)) l=mid;
		else r=mid;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>r+1) break;
		cnt++;
		ans+=(r+1-a[i]);
	}
	if(ans<=m && cnt>maxs) maxs=cnt;
	cout<<maxs;
	return 0;
}
