#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll n;
inline ll read(){
    ll a=0;
    char c=getchar();
    bool pd=0;
    while(c<'0'||c>'9'){
        if(c=='-')pd=1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        a=a*10+c-'0';
        c=getchar();
    }
    if(pd==1)a*=-1;
    return a;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    printf("I Love wrq");
    return 0;
}

