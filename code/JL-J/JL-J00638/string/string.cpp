#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a[100000],n;
    char d[10000],d1,d2;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>d[i];
        }
    d[1]=d1;
    d[n]=d2;
    if(d1=d2) cout<<'0';
    else cout<<'1';
    return 0;
}


