#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N];
int b[N];
int v[N];
int s[N];
int d[N];
int n;
int m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(v[a[j]]==1){
                for(int z=j-1;z>=1;z--){
                    if(a[z]==a[j]){
                        s[z]=1;
                        break;
                    }
                    s[z]=1;
                }
            }
            else if(v[a[j]]==0)
                v[a[j]]=1;
        }
        for(int i1=i;i1<=n;i1++){
            if(s[i1]==0){
                b[a[i1]]++;
            }
        }
        for(int i2=1;i2<=n;i2++)
            v[a[i2]]=0;
        for(int i3=1;i3<=n;i3++)
            s[a[i3]]=0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(d[a[i]]==1)continue;
        d[a[i]]=1;
        cout<<b[a[i]];
        if(i!=n)cout<<" ";
    }
    return 0;
}
