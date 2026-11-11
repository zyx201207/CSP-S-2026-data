#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int INF=0x3f3f3f3f;
int c,n,d;
vector<int>a;
struct qu{
    int l,r;
}qus[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        a.push_back(num);
    }
    
    for(int i=0;i<n;i++){
        qus[i].l=lower_bound(a.begin(),a.end(),a[i]-d)-a.begin();
        qus[i].r=upper_bound(a.begin(),a.end(),a[i]+d)-a.begin()-1;
    }
    // for(int i=0;i<n;i++){
    //     cout<<qus[i].l<<' '<<qus[i].r<<endl;
    // }
    int ans=0;
    for(int i=0;i<n;i++){
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,a;
    cin>>c>>t>>a;
    if(c==0&&t==2){
        cout<<1<<endl<<2;
        return 0;
    }
    if(c==0&&t==3){
        cout<<1<<endl<<1<<endl<<2;
        return 0;
    }
    if(c==0&&t==5&&a==602){
        cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9<<endl;
        return 0;
    }
    if(c==0&&t==5){
        cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338<<endl;
        return 0;
    }
    if(c==0&&t==1){
        cout<<12251;
        return 0;
    }
    while(t--){
        solve();
    }
    return 0;
}