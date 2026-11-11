#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<int,char>a[1000005];
int m[1000005],mp[1000005],mpp[1000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second,sum+=a[i].first,m[a[i].second]=a[i].first;
	mp[a[1].second]=1;
	for(int i=2;i<=n;i++)mp[a[i].second]=mp[a[i-1].second]+a[i-1].first;
	for(int i=1;i<=n;i++)mpp[a[i].second]=mpp[a[i-1].second]+a[i].first;
	pair<int,char>l,r;
	l.first=1,l.second=a[1].second,r.first=sum,r.second=a[n].second;
	int L=1,R=n;
	while(l.first<r.first){
		if(l.second!=r.second){
			if(mp[a[L+1].second]-l.first<r.first-mpp[a[R-1].second]){
				ans+=mp[a[L+1].second]-l.first;
				r.first-=mp[a[++L].second]-l.first;
				l.first=mp[a[L].second];
				l.second=a[L].second;
			}else{
				ans+=r.first-mpp[a[R-1].second];
				l.first+=r.first-mpp[a[--R].second];
				r.first=mpp[a[R].second];
				r.second=a[R].second;
			}
		}else{
			if(mp[a[L+1].second]-l.first<r.first-mpp[a[R-1].second]){
				r.first-=mp[a[++L].second]-l.first;
				l.first=mp[a[L].second];
				l.second=a[L].second;
			}else{
				l.first+=r.first-mpp[a[--R].second];
				r.first=mpp[a[R].second];
				r.second=a[R].second;
			}
		}
	}cout<<ans;
	return 0;
}
