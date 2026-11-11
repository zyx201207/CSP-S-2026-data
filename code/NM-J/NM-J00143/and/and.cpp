#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,l=0,k,y=0;
    cin>>n>>m;
    int a[n+5][100]={0};
    for(int b=1;b<=n;b++){
        int h;
        cin>>h;
        for(int f=1;h!=0;f++){
            a[b][f]=h%2;
            h/=2;}}
    for(int j=1;j<=n-1;j++)
        for(int i=j;i<=n-1;i++){
            for(int f=1;a[j][f]!=0&&a[i][f]!=0;f++)
                y=y*10+(a[j][f]&&a[i][f]);}
            l=max(y,l);
    for(int j=1;j<=n-1;j++)
        for(int i=j;i<=n-1;i++){
            for(int f=1;a[j][f]!=0&&a[i][f]!=0;f++)
                y=y*10+(a[j][f]&&l)
            l=max(y,l);
    cout<<l;
    return 0;
}
