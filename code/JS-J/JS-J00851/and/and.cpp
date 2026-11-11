#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200007;
int n,m,ans,a[N];
struct node{
    string s;
    int t,c;
}x[N];
bool cmp(node i,node j){
    if(i.c!=j.c)return i.c>j.c;
    return i.s>j.s;
}
vector<int>v;
void dfs(int x){
    if(v.size()==m){
        int sum=a[v[0]];
        for(auto i:v){
            sum=sum&a[i];
        }
        ans=max(sum,ans);
        return;
    }
    if(x>n)return;
    v.push_back(x);
    dfs(x+1);
    v.pop_back();
    dfs(x+1);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        int tmp=a[i];
        string s;
        while(tmp){
            if(tmp&1)s+="1",x[i].c++;
            else s+="0";
            tmp>>=1;
        }
        x[i].s=s;
        x[i].t=i;
    }
    sort(x+1,x+1+n,cmp);
    ans=a[x[1].t];
    for(int i=2;i<=m;i++){
        ans=ans&a[x[i].t];
    }
    cout<<ans;
    return 0;
}
/*
Think:

0011
1111
1100
1100

11111
00011
00001
01111
00111
*/
