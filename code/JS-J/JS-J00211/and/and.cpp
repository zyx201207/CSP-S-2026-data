#include<bits/stdc++.h>
using namespace std;
#define int long long
ifstream fin("and.in");
ofstream fout("and.out");
#define cin fin
#define cout fout
int n,m;
int a[200005];
int res=0;
vector<int> bt[35];
bool t[200005];
bool t2[200005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        for(int j=0;j<=31;++j)
            if(a[i]&(1<<j)) bt[j].push_back(i);
    }
    for(int i=1;i<=n;++i) t[i]=1;
    for(int i=31;i>=0;--i){
        if(bt[i].size()<m) continue;
        int s=0;
        for(int j=1;j<=n;++j) t2[j]=0;
        for(int j:bt[i]) t2[j]=1;
        for(int j=1;j<=n;++j){
            if(t[j]&&t2[j]){
                t[j]=1;
                s++;
            }
            else t[j]=0;
        }
        if(s>=m) res+=(1<<i);
    }
    cout<<res<<"\n";
    return 0;
}
