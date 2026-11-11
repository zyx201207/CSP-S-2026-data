#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6+114;
int f[maxn][2];
int L[maxn],R[maxn];
int pos[maxn];
int n,d;
//记得多测清空
vector<int> LI[maxn],RJ[maxn];
vector<int> D[maxn];
void work(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>pos[i];
        L[i]=i,R[i]=i;
    }
    int l=1;
    for(int i=1;i<=n;i++){
        while(abs(pos[i]-pos[l])>d) l++;
        L[i]=l;
    }
    int r=n;
    for(int i=n;i>=1;i--){
        while(abs(pos[i]-pos[r])>d) r--;
        R[i]=r;
    }
    for(int i=1;i<=n;i++) D[L[L[i]]].push_back(i);
    for(int x=1;x<=n;x++){
        for(int i:D[x]){
            if(i>L[i]+1) LI[L[i]].push_back(L[L[i]]);
        }
    }
    for(int j=1;j<=n;j++) RJ[R[j]].push_back(j);
    for(int i=1;i<=n;i++){
        //j 转移到 R[j]
        //f[j][0] -> f[i][1]
        f[i][0]++;//从自己开始
        int t=R[i];
        if(t>i){
            //f[j][0] -> f[i][0]
            //f[j][1] -> f[i][1]            
            if(L[t]==i) f[t][0]+=f[i][0];
            else if(i>L[t]) f[t][0]++;
            if(L[t]==i) f[t][1]+=f[i][1];
        }
        t=R[R[i]];
        if(t>i){
            if(R[i]==L[t]+1){
                if(R[R[i]]==t&&R[L[t]]==t&&R[i]<t){
                    if(L[R[i]]==i&&L[L[t]]==i) f[t][1]+=f[i][0];
                    else if(i>L[L[t]]) f[t][1]++;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        //f[j][1] -> ans
        if(L[i]<i) ans+=f[L[i]][1];
        int j=L[L[i]];
        if(R[j]==L[i]+1){
            if(i>R[j]){
                if(L[R[j]]==j&&L[L[i]]==j) ans+=f[j][0];
            }
        }
    }
    //f[j][0] -> ans
    for(int p=1;p<n;p++){
        //赵 LI[p] 中有多少个 <j 的即可
        int tp=-1;
        for(int j:RJ[p+1]){
            while(tp+1<(int)LI[p].size()&&LI[p][tp+1]<j) tp++;
            ans+=(tp+1);
        }
    }
    cout<<ans<<"\n";
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        work();
        for(int i=0;i<=n;i++){
            L[i]=R[i]=f[i][0]=f[i][1]=0;
            LI[i].clear();
            RJ[i].clear();
            D[i].clear();
        }
    }
    return 0;
}