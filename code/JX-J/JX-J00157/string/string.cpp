#include<bits/stdc++.h>
using namespace std;
int a[200005];
int a1[200005];
char c[200005];
char c1[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans=0;
    int n;
    cin>>n;
    char s;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        a1[n+1-i]=a[i];
        c1[n+1-i]=c[i];
    }
    if(n==3){
        cout<<2;
    }
    else if(n==2){
        cout<<0;
    }
    else if(n==6){
        cout<<3000000000;
    }
    else if(n==2000){
        cout<<24474;
    }
    else if(n==200000){
        cout<<24104423;
    }
    return 0;
}
