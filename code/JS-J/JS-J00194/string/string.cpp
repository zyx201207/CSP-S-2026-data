#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ai,s,e,sum=0;
string ci;
const int maxn1=6e7;
const int maxn2=2e5+5;
string  a[maxn1],c[maxn2];
int b[maxn2];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    e=0;
    for(int i=1;i<=n;i++){
        cin>>ai>>ci;
        e+=ai;
        b[i]=ai;
        c[i]=ci;
    }
    int j=0;
    for(int i=1;i<=n;i++){
        for(int z=1;z<=b[i];z++){
            a[j+z]=c[i];
        }
        j+=b[i];
    }
    s=1;
    while(e>=s){
        if(a[s]!=a[e])sum++;
        s++;
        e--;
    }
    cout<<sum;
}
