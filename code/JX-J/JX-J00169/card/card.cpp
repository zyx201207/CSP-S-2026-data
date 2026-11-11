#include<bits/stdc++.h>
using namespace std;

int n,m,a[501000],aa[500100],i=1,leng;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int ans[m];
    memset(ans,0,sizeof ans);
    cin>>n>>m;
    for(int j=0;j<n;j++)cin>>aa[i];
    int t=n;
    while(t--){
        for(int j=0;j<n;j++)a[i]=aa[i];
        int x=0;
        for(int j=i;j<n;j++){
            x=a[j];
            a[j]=0;
            bool f=true;
            int y;
            for(y=j+1;y<leng;y++){
                if(a[y]==x){
                    for(int z=y;z<n;z++)a[z]=0;
                    break;
                }
            }
            a[y]=x;
            leng=y+1;
        }
        for(int z=1;z<m;z++){
            for(int j=0;j<leng;j++){
                if(a[j]==z){
                    ans[z]++;
                    break;
                }
            }
        }
        memset(a,0,sizeof a);
    }
    for(int j=0;j<m;j++){
        cout<<ans[j]<<' ';
    }
    cout<<"\n";

    return 0;
}
