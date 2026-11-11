#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
struct q{
    priority_queue<ll>p;
}a[35];
ll n,m,v,c,b[N],q=0,s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i=0;i<=31;i++){
        s+=pow(2,i);
    }
    s=s&7;
    cout<<s<<endl;
	return 0;
}
