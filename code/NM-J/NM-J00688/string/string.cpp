#include<bits/stdc++.h>
using namespace std;
bool x=0;
char a,b[200005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>a;
        int k=0;
        for(int j=1;j<=m;j++){
            k++;
            b[k]=a;
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=b[i+1]&&b[i+1]!=0) x=1;
    }
    if(x==0){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
       if(b[i-1]!=b[i]&&b[i+1]!=b[i]&&b[i-1]!=0&&b[i+1]!=0) ans++;
    }
    cout<<ans;
    return 0;
}
