#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int t,w;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    t=1,w=n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    while(t<w){
        if(a[t]>a[w]){
            if(c[t]!=c[w]){
                ans+=a[w];
            }
            a[t]-=a[w];
            w--;
        }else if(a[t]<a[w]){
            if(c[t]!=c[w]){
                ans+=a[t];
            }
            a[w]-=a[t];
            t++;
        }else{
            if(c[t]!=c[w]){
                ans+=a[t];
            }
            t++;
            w--;
        }
    }
    cout<<ans;
    return 0;
}
