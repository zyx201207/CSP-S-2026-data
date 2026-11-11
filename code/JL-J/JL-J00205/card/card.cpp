#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<n;j++){
            if(a[j]==a[i]){
                for(int u=a[j];u<n;u++)
                    a[u]=0;
            }
        }
        if(a[i]==m)
            t=i+1;
    }
    for(int i=1;i<n;i++)
        if(a[i]!=0)
            cout<<a[i]<<' ';
    cout<<t;
    return 0;
}
