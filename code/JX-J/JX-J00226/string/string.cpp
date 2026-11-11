#include<bits/stdc++.h>
using namespace std;
char S[200005],c[200000],b[200005];
int a[200000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long op=1;
    int k=1;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=op;j<=a[i];j++){
            S[j]=c[i];
        }
        op+=a[i];
    }
    for(int i=n;i>=1;i--){
        S[i]=b[k];
        k++;
    }
    int m=1;
    for(int i=1;i<=n;i++){
        if(S[i]!=b[i]) m=0;
    }
    if(m==1) cout<<0;

    return 0;
}
