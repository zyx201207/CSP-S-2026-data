#include<bits/stdc++.h>
using namespace std;
struct note{
    long long v;
    string s;
}a[10000000];
long long n,m,cnt=1,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].v>>a[i].s;
    }
    long long l=1,r=n;
    while(1){
        if(l>=r){
            break;
        }
        long long b=min(a[l].v,a[r].v);
        if(a[l].v==a[r].v){
            if(a[l].s==a[r].s){
                l++;
                r--;
            }
            else{
                ans+=a[l].v;
                l++;
                r--;
            }
        }
        else if(b==a[l].v){
            if(a[l].s==a[r].s){
                a[r].v-=a[l].v;
                l++;
            }
            else{
                ans+=a[l].v;
                a[r].v-=a[l].v;
                l++;
            }
        }
        else if(b==a[r].v){
            if(a[l].s==a[r].s){
                a[l].v-=a[r].v;
                r--;
            }
            else{
                ans+=a[r].v;
                a[l].v-=a[r].v;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
