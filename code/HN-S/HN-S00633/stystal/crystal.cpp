#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m,a[N],c,m1,ans=1,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		m1=m;
		cnt=1;
		for(int j=i-1;j>=1;j--){
			c=a[i]-a[j];
			if(c>m1){
				break;
			}
			m1-=c;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
