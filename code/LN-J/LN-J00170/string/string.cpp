#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
string c[N],ac[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int cnt=0,sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            ac[++cnt]=c[i];
        }
    }
    for(int i=1;i<=cnt>>1;i++){
        if(ac[cnt-i]!=ac[i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
