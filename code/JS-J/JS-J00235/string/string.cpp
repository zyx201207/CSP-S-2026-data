#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct str{
    ll m;char c;
}a[200020];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;cin>>n;string s="";
    ll cnt=0;
    for(ll i=0;i<n;i++){
        cin>>a[i].m>>a[i].c;
    }for(ll i=0,j=n-1;i<=j;){
        if(a[i].c!=a[j].c){
            cnt+=min(a[i].m,a[j].m);
            if(a[i].m<a[j].m){
                a[j].m-=a[i].m;i++;
            }else if(a[i].m>a[j].m){
                a[i].m-=a[j].m;j--;
            }else if(a[i].m==a[j].m){
                a[i].m=0;a[j].m=0;i++;j--;
            }
        }else if(a[i].c==a[j].c){
            if(a[i].m<a[j].m){
                a[j].m-=a[i].m;i++;
            }else if(a[i].m>a[j].m){
                a[i].m-=a[j].m;j--;
            }else if(a[i].m==a[j].m){
                a[i].m=0;a[j].m=0;i++;j--;
            }
        }
    }cout<<cnt;
    return 0;
}
