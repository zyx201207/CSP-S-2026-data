#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,i,t,w,ans;
int a[210000];
char c[210000];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i]>>c[i];
    t=1;
    w=n;
    while(t<=w){
    	if(a[t]<a[w]){
    		if(c[t]!=c[w]) ans+=a[t];
			a[w]-=a[t];
			t++;
		}
    	else if(a[t]==a[w]){
    		if(c[t]!=c[w]) ans+=a[t];
			t++;
			w--;
		}
		else{
			if(c[t]!=c[w]) ans+=a[w];
			a[t]-=a[w];
			w--;
		}
	}
	cout<<ans;
}