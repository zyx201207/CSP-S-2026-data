#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
    ll x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
void write(ll x){
    if(x<0)x=-x,putchar('-');
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll x=read();
    write(x);
    return 0;
}
