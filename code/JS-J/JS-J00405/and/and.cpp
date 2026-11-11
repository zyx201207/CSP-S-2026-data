#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int n,m,ls[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ls[i];
    }
    sort(ls+1,ls+1+n);
    if(m==1){
        cout<<ls[n]<<endl;
        return 0;
    }//5pts
    if(m==n){
        int sum=ls[1]&ls[2];
        for(int i=3;i<=n;i++){
            sum&=ls[i];
        }
        cout<<sum<<endl;
        return 0;
    }//5pts
    cout<<ls[n-m+1]<<endl;
    return 0;
}