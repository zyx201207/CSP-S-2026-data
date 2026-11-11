#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+5;
LL n,m,a[N],s[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=2,r,p;
	for(int i=1;i<=n;i++){
		p=a[i]*i-s[i];
		if(p>m){
			r=i;
			ans=i-1;
			break;
		}
	}
	for(int i=r;i<=n;i++){
		while(1){
			LL tmp=a[i]*(i-l)-(s[i]-s[l-1]);
			if(tmp<=m){
				ans=max(ans,i-l);
				break;
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
