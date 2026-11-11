#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=5e5+5;
int a[maxn];
int ans[maxn];

bool f=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            f=0;
        }
    }
    if(f){
        for(int i=1;i<=m;i++){
            cout<<i;
            if(i<m)cout<<" ";
        }
    }else{
        for(int i=1;i<=n;i++){
            int book[maxn];
            int tt[maxn];
            int cc=1;
            for(int j=i;j<=n;j++){
                if(!book[a[j]]){
                    tt[cc]=a[j];
                    book[a[j]]=1;
                    cc++;
                }else{
                    while(tt[cc-1]!=a[j]){
                        cc--;
                    }
                }

            }
            for(int i=1;i<=cc;i++){
                ans[tt[cc]]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i];
        }
    }
    return 0;
}
