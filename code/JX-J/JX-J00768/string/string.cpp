#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt;
unsigned long long N;
char c[200005];
char find(int x){
    int ct=1;
    int ci=1;
    while(1){
        if(ct+a[ci]>N-x+1){
            return c[ci];
            break;
        }
        ct+=a[ci];
        ci++;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++) N+=a[i];
    for(int i=1;i<=N/2;i++)
        if(c[i]!=find(i)) cnt++;
    cout<<cnt;
    return 0;
}
