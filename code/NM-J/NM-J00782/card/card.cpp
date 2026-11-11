#include<bits/stdc++.h>
using namespace std;
int n,m,l;
int a[500005],b[500005];
string s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        l++;
        for(int j=l;j<=n;j++){
            if(a[j+1]!=a[j]){
                b[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}

