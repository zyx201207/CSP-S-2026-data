#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int k=1;
    cin>>n>>m;
    if(m==2){
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(a[1]==x){
                cout<<1<<' ';
                a[2]=0;
                a[1]=x;
                ans[x]++;
            }else if(a[2]==x){
                cout<<2<<' ';
                a[2]=x;
                ans[x]++;
                ans[3-x]++;
            }else if(a[1]==0){
                cout<<3<<' ' ;
                a[1]=x;
                ans[x]++;
            }else if(a[2]==0){
                 a[2]=x;
                 ans[x]++;
                ans[3-x]++;
            }
        }
        cout<<ans[1]<<' '<<ans[2];
    }
    return 0;
}
