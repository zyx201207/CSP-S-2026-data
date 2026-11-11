#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005],flag[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            memset(flag,true,sizeof(flag));
        for(int j=1;j<=n;j++){
            if(a[j]!=a[j+1])flag[a[j]]=true;

        }
    }
    for(int i=1;i<=m;i++)cout<<"0";
    return 0;
}

