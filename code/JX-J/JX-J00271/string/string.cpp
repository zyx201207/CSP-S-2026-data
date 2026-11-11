#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans=0;
struct dlm{
    long long cnt;
    char ch;
}a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].cnt>>a[i].ch;
    long long i=1,r=n;
    while(1){
        if(i>=r) break;
        if(a[i].cnt>a[r].cnt){
            if(a[i].ch!=a[r].ch) ans+=a[r].cnt;
            a[i].cnt-=a[r].cnt;
            r--;
        }else if(a[i].cnt<a[r].cnt){
            if(a[i].ch!=a[r].ch) ans+=a[i].cnt;
            a[r].cnt-=a[i].cnt;
            i++;
        }else{
            if(a[i].ch!=a[r].ch) ans+=a[i].cnt;
            a[r].cnt=0;
            r--;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
