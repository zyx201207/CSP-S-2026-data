#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],sum[1000005];
struct node{
    int x,f;
}s[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int p=1,ans[1000005]={0};
        for(int j=1;j<=n;j++){
            s[i].x=0;
            s[i].f=0;
        }
        for(int j=i;j<=n;j++){
            if(s[a[j]].f==0){
                s[a[j]].f=1;
                s[a[j]].x=p;
                ans[p]=a[j];
                p++;
            }else{
                p=s[a[j]].x;
                ans[p]=a[j];
                p++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}


