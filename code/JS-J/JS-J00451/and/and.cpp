#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define endl '\n'
const int inf=0x3f3f3f3f;
const double eps=1e-9;
using namespace std;

const int maxn=200005;
int n,m,a[maxn],cur=31,ans;
bool ok[maxn];

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ok[i]=1;
    }
    while(cur>0){
        int cnt=0; cur--;
        for(int i=1;i<=n;i++) if(ok[i] && (a[i]&(1<<cur))) cnt++;
        if(cnt<m) continue;
        for(int i=1;i<=n;i++) if(!(a[i]&(1<<cur))) ok[i]=0;
        ans+=(1<<cur);
    }
    cout<<ans;
    //09:15

    return 0;
}
