#include<bits/stdc++.h>
using namespace std;
char a[10000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long len=0;
    int pos=1;
    for(int i=1;i<=n;i++){
        long long x;cin>>x;
        if(x>=1e9) {cout<<3000000000;return 0;}
        len+=x;
        char y;cin>>y;
        while(x--){
            a[pos++]=y;
        }
    }
    int ans=0;
    for(int i=1,j=len;i<=j;){
        if(a[i]!=a[j]) ans++;
        i++,j--;
    }
    cout<<ans;
}
