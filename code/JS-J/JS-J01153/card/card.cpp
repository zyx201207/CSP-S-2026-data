#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1)cout<<1;
    for(int i=1;i<=n;i++){
        int t[N]={};
        for(int j=i;j<=n;j++){
            t[a[j]]++;
            if(t[a[j]]>1){
                for(int k=1;k<i;k++){
                    a[k]=0;
                    t[a[k]]--;
                }
            }
        }
       for(int h=1;h<=m;h++){
        if(t[h]!=0)ans[h]++;
       }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
