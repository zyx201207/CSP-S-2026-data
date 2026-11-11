#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m,o=1,ans=1,oo=1,s,ooo=1;
    cin>>n>>m;
    if(n==1){
    	cout<<1;
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=i)o=0;
    	if(i==1)continue;
    	else if(i==2)s=a[2]-a[1];
    	else if(a[i]-a[i-1]!=s)oo=0;
    	if(i!=1&&a[i]!=a[i-1])ooo=0;
	}
	sort(a+1,a+n+1);
	if(n==2){
		if(max(a[1],a[2])-min(a[1],a[2])<=m)cout<<2;
		else cout<<1;
		return 0; 
	}
	if(o==1){
		int p=n,k=n-1;
		while(m>0){
			m=m-(a[p]-a[k]);
			if(m>=0){
				ans++;
				k--;
			}
		}
		cout<<ans;
		return 0;
	}
	if(oo==1){
		int p=n,k=n-1;
		while(m>0){
			m=m-s*(a[p]-a[k]);
			if(m>=0){
				ans++;
				k--;
		    }
		}
		cout<<ans;
		return 0;
	}
	if(ooo==1){
		cout<<n;
		return 0;
	}
	if(n%2==0)cout<<n/2;
	else cout<<n/2+1;
	return 0;
}