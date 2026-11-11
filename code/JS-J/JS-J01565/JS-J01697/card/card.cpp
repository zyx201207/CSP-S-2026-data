#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[300005],c[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]==a[i]){
                c[i]=j;
                break;
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            while(c[j]!=0){
                j=c[j];
            }
            b[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
