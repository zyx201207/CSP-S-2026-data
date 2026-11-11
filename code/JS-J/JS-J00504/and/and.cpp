#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m,ans;
int cnt[31];
vector <int> v;
struct node{
    int val,len,f[31];
}a[N];
bool cmp(node x,node y){
    for(auto i:v)
        if(x.f[i]!=y.f[i]) return x.f[i]>y.f[i];
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x,num=0;
        cin>>x;
        a[i].val=x;
        while(x){
            a[i].f[num]=(x%2);
            cnt[num]+=(x%2);
            num++;
            x/=2;
        }
        a[i].len=num+1;
    }
    for(int i=31;i>=0;i--)
        if(cnt[i]>=m) v.push_back(i);
    sort(a+1,a+n+1,cmp);
    ans=a[1].val;
    for(int i=2;i<=m;i++) ans=(ans&a[i].val);
    cout<<ans;
    return 0;
}
