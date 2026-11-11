#include<bits/stdc++.h>
#define int long long
#define Max 1e18+7
using namespace std;
const int N=5e5+7;
int n,d,c,t;
vector<int > a;
vector<int > re;
vector<int > tag;
int haonan=0;
void dfs(int now,int len){
    if(re[now]==len)
        tag[now]++;
    if(len<re[now]){
        re[now]=len;
        tag[now]=1;
    }
    if(len>re[now])
        return;
    if(now==n)
        return;
    for(int ne=now+1;a[now]+d>=a[ne];ne++){
        dfs(ne,len+1);
    }
    return;
}
void goushibaoli(){
    haonan=0;
    a.clear();
    re.clear();
    tag.clear();
    cin>>n>>d;
    a.push_back(0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        re.push_back(Max);
        tag.push_back(0);
    }
    for(int i=1;i<=n;i++){
        dfs(i,0);
        for(int j=1;j<=n;j++){
            if(tag[j]==2){
                haonan++;
            }
            tag[j]=0;
            re[j]=0;
        }
    }
    cout<<haonan<<endl;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(--t)goushibaoli();
    goushibaoli();
    return 0;
}
