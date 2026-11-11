#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int d;
    ll s=0,k=0;
    cin>>d;
    string h="";
    for(int i=0;i<d;i++){
        ll g;
        char m;
        cin>>g>>m;
        for(int i=0;i<g;i++)h+=m;
        s+=g;
    }
    ll l=s/2;
    for(int i=0;i<l;i++){
        int m=s-1-i;
        if(h[m]!=h[i])k++;
    }
    cout<<k;
    return 0;
}
