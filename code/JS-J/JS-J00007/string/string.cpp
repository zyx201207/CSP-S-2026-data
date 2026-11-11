#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct Node{
    int x;
    char ch;
}a[N];
int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    ll res=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].ch;
        res=res+a[i].x;
    }
    ll be=0,ed=n;
    ll ans=0;
    ll mid=res/2;
    bool ok=0;
    for(int i=1;i<=n;i++){
        ll tmp=0;
        char c=a[i].ch;
        if(be+a[i].x<=mid){
            be+=a[i].x;
            tmp=a[i].x;
        }else{

            tmp=mid-be+1;
            be=mid;
            ok=1;
        }
        while(tmp){
            int xx=a[ed].x;
            char cc=a[ed].ch;
            if(tmp>=a[ed].x){
                tmp-=a[ed].x;
                if(cc!=c)ans+=a[ed].x;
                a[ed].x=0;
                ed--;
            }else{
                a[ed].x-=tmp;
                if(cc!=c)ans+=tmp;
                tmp=0;
            }
        }
        if(ok)break;
    }
    cout<<ans<<endl;
    return 0;
}
