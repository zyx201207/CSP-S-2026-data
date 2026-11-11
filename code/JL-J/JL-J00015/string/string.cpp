#include<bits/stdc++.h>
using namespace std;
int n;
int a[220000];
char c[220000];
long long s,t,ans;
int ni,nj;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    ni=1,nj=n;
    s=a[ni],t=a[nj];
    while(ni<nj){
        if(s>t){
            if(c[ni]!=c[nj]) ans+=t;
            s-=t;
            nj--;
            t=a[nj];
        }else if(t>s){
            if(c[ni]!=c[nj]) ans+=s;
            t-=s;
            ni++;
            s=a[ni];
        }else{
            if(c[ni]!=c[nj]) ans+=s;
            s=a[++ni];
            t=a[--nj];
        }
    }
    cout<<ans;
	return 0;
}
