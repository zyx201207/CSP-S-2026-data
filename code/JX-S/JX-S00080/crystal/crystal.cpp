#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];//,c[500005],cnt;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);

    int maxn=0;
    //for(int i=1;i<=n;i++){
        //for(int j=1;j<=i;j++){
            //if(i==j){
                //continue;
            //}
            //c[i][j]=c[i-1][j]+(i-j)*(a[i]-a[i-1]);
            //if(c[i][j]<=m&&i-j+1>maxn)maxn=i-j+1;


        //}
    //}
    for(int i=1;i<=n;i++){
            long long last=0;
        for(int j=i;j<=n;j++){
            if(i==j){
                continue;
            }
            last+=(j-i)*(a[j]-a[j-1]);
            if(last<=m&&j-i+1>maxn)maxn=j-i+1;


        }
    }
    cout<<maxn;

    return 0;
}
