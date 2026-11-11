#include<bits/stdc++.h>
using namespace std;
int k;
char b[2000000001],l;
int main(){
    freopen("string.in","read",stdin);
    freopen("string.out","write",stdout);
    int n,m=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>l;
        for(int j=1;j<=k;j++){
            b[++cnt]=l;
        }
    }
    for(int i=1;i<=cnt/2;i++){
        if(b[i]!=b[cnt-i]) m++;
    }
    cout<<m;
    return 0;
}
