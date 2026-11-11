#include<bits/stdc++.h>
using namespace std;
long long n,m[100086],b;
string a[100086];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>m[i]>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]==a[i+1]) b=1;
        else b=0;
    }
    if(b==1) cout<<"0";
    else cout<<"2";
    return 0;
}
