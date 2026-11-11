#include<bits/stdc++.h>
using namespace std;
int a[500005];
int d[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=n+1;
    while(--t){
        int b[300005];
        int c[300005];
        for(int i=0;i<=m;i++){
            b[i]=0;
            c[i]=0;
        }
        int x=1;
        for(int i=t;i<=n;i++){
            if(b[a[i]]!=0){
                for(int j=x-1;j>=b[a[i]];j--){
                    b[c[j]]=0;
                    c[j]=0;
                }
                x=b[a[i]]+1;
            }
            else{
                c[x]=a[i];
                x++;
                b[a[i]]=x;
            }
        }
        for(int i=0;i<=x;i++){
            d[c[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<' ';
    }
    return 0;
}
