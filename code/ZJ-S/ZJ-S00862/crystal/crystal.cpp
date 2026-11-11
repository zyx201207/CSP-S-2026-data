#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ma,t,w,s,ans,a[500010],b[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    t=0,w=0;ans=0;s=0;
    while(w<=n){
    	while(ans>m)
		    ans-=(a[w]-a[t]),s-=a[t],t++; 
    	ma=max(ma,w-t+1);
		w++;
    	s+=a[w];
    	ans=a[w]*(w-t+1)-s;
	}
	cout<<ma;
}
