#include <bits/stdc++.h>
using namespace std;
long long n,a[500000005],ans=0,y  ,t,yt;
string c[500000005],w,p;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ans+=a[i];
        for(int j=a[i];j>=1;j--){
            w+=c[i];
        }
    }
    for(int i=1;i<=ans;i++){
        p+=c[1];
    }
    if(p==w){
        cout<<0;
        return 0;
    }
    t=w.size()-1;
    while(t!=y){
        if(w[y]!=w[t]){
            yt++;
        }
        t--;
        y++;
    }
    cout<<yt;
    return 0;
}
