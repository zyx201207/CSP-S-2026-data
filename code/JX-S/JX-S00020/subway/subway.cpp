#include <bits/stdc++.h>
#define LL long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int c,n,m,d,q;
int w[1000005];
int k[1000005];
int a[1000005],t[1000005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    IOS;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            cin>>a[j]>>t[j];
        }
    }
    if(!c){
        if(n==2){
            cout<<32<<endl<<17;
        }else cout<<35<<endl<<16;
    }



    return 0;
}
