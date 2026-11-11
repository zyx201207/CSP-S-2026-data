#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
    char c;
    ll num;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ll mis=0;
    for(int i=1;i<=n;i++){
            cin>>a[i].num>>a[i].c;
            mis+=a[i].num;
    }
    ll ans=0;
    ll j=n;
    ll i=1,cnt=0;
    while(cnt<mis/2){
        if(i==j) break;
        if(a[j].num<a[i].num){
            a[i].num-=a[j].num;
            if(a[i].c!=a[j].c){
                ans+=a[j].num;
            }
            cnt+=a[j].num;
            j--;
        }else{
            if(a[i].c!=a[j].c){
                ans+=a[i].num;
            }
            a[j].num-=a[i].num;
            cnt+=a[i].num;
            i++;
        }

    }
    cout<<ans<<'\n';
    return 0;
}
