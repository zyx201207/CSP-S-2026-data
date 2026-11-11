#include<bits/stdc++.h>
using namespace std;
long long n,m,maxc;
long long a[500010],d[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	map<long long,long long>mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		maxc=max(maxc,mp[a[i]]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	long long sum=0,cnt=1;
	for(int i=2;i<=n;i++){
		sum+=d[i]*(i-1);
		if(sum<=m){
			cnt++;
		}
		else{
			break;
		}
	}
	cout<<max(cnt,maxc);
	return 0;
}
