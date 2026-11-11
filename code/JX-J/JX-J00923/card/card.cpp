//RP++ code has no bug!
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int shu[N],a[N],pre[N],ans[N],weizhi[N];
struct Node{
    int a,pos;
}num[N];
struct edge{
    int l,r;
}ed[N];
bool cmp(Node x,Node y){
    if(x.a==y.a)return x.pos<y.pos;
    else return x.a<y.a;
}
void add(int l,int r){
    pre[l]-=l;
    pre[r+1]+=l;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num[i].a=a[i];
        num[i].pos=i;
        shu[a[i]]++;
    }
    for(int i=1;i<=m;i++)weizhi[i]=weizhi[i-1]+shu[i-1];
    for(int i=1;i<=n;i++){
        int l=weizhi[a[i]]+1,r=weizhi[a[i]]+shu[a[i]],ans=-1;
        while(l<=r){
            int mid=l+((r-l)>>1);
            if(num[mid].pos<=i){
                l=mid+1;
                ans=mid;
            }else r=mid-1;
        }
        if(ans==weizhi[a[i]]+1)continue;
        else{
            l=num[ans-1].pos,r=num[ans].pos;
            add(l,r);
        }
    }
    for(int i=1;i<=n;i++)ans[a[i]]=max(max(i+pre[i],0LL),ans[a[i]]);
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
