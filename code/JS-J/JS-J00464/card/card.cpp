#include<bits/stdc++.h>
using namespace std;
long long a[500005],l[300005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            for(long long k=j;k<=n;k++)
                if(a[k]==a[j])
                    j=k;
            l[a[j]]++;
        }
    }
    for(long long i=1;i<=m;i++)
        cout<<l[i]<<" ";
    return 0;
}
