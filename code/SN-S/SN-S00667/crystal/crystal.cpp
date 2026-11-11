#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005],k,cnt=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	k=m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1,j=1;i<n;i++){
		if((a[i+1]-a[i])*(i-j+1)<=m){
			m-=(a[i+1]-a[i])*(i-j+1);
			cnt++;
		}
		else{
			if(a[i]+k<a[i+1]){
				m=k;
				ans=max(cnt,ans);
				cnt=0;
				j=i+1;
				continue;
			}
			ans=max(ans,cnt);
			while((a[i+1]-a[i])*(i-j+1)>m){
				m+=a[i]-a[j++];
				cnt--;
			}
			m-=(a[i+1]-a[i])*(i-j+1);
			cnt++;
		}
	}
	cout<<max(ans,cnt);
	return 0;
}
