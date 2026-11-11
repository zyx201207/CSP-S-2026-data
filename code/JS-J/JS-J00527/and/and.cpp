#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool b[35][200005];
bool c[200005];
int ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<30;j++){
            b[j][i]=a[i]&(1<<j);
        }
    }
    for(int j=29;j>=0;j--){
        int x=0;
        for(int i=1;i<=n;i++){
            x+=(!c[i])&&b[j][i];
        }
        if(x<m) continue;
        ans+=1<<j;
        for(int i=1;i<=n;i++){
            if(!b[j][i]) c[i]=true;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
//g++ and.cpp -o and -std=c++11