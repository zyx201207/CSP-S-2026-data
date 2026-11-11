#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
struct mmp{
    ll co;
    char s;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll cnt=0;
    for(int i = 1;i<=n;i++){
        ll x;
        char y;
        cin>>x>>y;
        if(y==a[cnt].s){
            a[cnt].co+=x;
        }
        else{
            cnt++;
            a[cnt].co=x;
            a[cnt].s=y;
        }
    }
    ll ans=0;
    ll head=1;
    ll tail=cnt;
    while(head<=tail){
        if(a[head].s!=a[tail].s){
            if(a[head].co==a[tail].co) ans+=a[tail].co;
            else{
                if(a[head].co>a[tail].co) ans+=a[tail].co;
                else ans+=a[head].co;
            }
            if(a[head].co-a[tail].co<0){
                a[tail].co-=a[head].co;
                head++;
            }else if(a[head].co-a[tail].co>0){
                a[head].co-=a[tail].co;
                tail--;
            }else{
                head++;
                tail--;
            }
        }
        else{
            if(a[head].co-a[tail].co<0){
                a[tail].co-=a[head].co;
                head++;
            }else if(a[head].co-a[tail].co>0){
                a[head].co-=a[tail].co;
                tail--;
            }else{
                head++;
                tail--;
            }
        }
    }
    cout<<ans;
    return 0;
}
