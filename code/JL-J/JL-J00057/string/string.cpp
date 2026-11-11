#include <bits/stdc++.h>
using namespace std;
int t[2000005],t1[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0,XDR=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long m;
        char a;
        cin>>m>>a;
        for(int j=sum+1;j<=m+sum+1;j++) t[j]=int(a)-96;
        sum+=m;
    }
    for(int i=1;i<=sum;i++)t1[i]=t[sum-i+1];
    for(int i=1;i<=int(sum/2);i++) if(t1[i]!=t[i]) XDR++;
    cout<<XDR;
    return 0;
}
