#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1000;
char a[N];
int n,m = 0;
int cnt = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int u;
        char v;
        cin>>u>>v;
        for(int j=m+1;j<=m+u;j++){
            a[j] = v;
        }
        m+=u;
    }
    if(m==n){
        cout<<n/2;
    }else{
     for(int i=1;i<=n/2+1;i++){
        if(a[i]!=a[m-i+1]){
            cnt++;
        }
    }
cout<<cnt;
    }
return 0;
}
