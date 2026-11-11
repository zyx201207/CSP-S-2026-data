#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010],n,ans[300010],m,c[300010],s[500010],d=0,p=0;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	p=n;
	for(int i=n;i>=1;i--){
		if(c[a[i]]!=0) d=1;
		if(d==0){
			if(c[a[i]]==0){
				c[a[i]]=i;
				s[i]+=1;
				p--;
			}
		}else {
			if(c[a[i]]==0){
			   c[a[i]]=i;
		    }
			int j=c[a[i]];
	    	while(j<=p){
		 	    s[j]+=1;
		   	    s[++j]-=1;
				j=c[a[j]];
		    }
			s[j]+=1;
		}
	}
	ll u=0;
	for(int i=1;i<=n;i++){
		u+=s[i];
		ans[a[i]]=max(ans[a[i]],u);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
