#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int k=1;
    while(k<=n){
        bool f=0;
        int id;
        for(int i=n-1;i>=k;i--){
            if(a[i]==a[n]){
                f=1;
                continue;
            }
        }
        if(f==0){
            for(int i=id;i<=n;i++)
                b[i]++;
        }
        k++;
    }
    for(int i=1;i<=m;i++)
        cout<<b[i]<<" ";
    return 0;
}
