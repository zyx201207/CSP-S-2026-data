#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,sta[200005],p;
void dfs(long long x,long long dep){
    if(dep==m){
        long long s=sta[0];
        //cout<<s<<" ";
        for(int i=1;i<m;++i){
            s&=sta[i];
            //cout<<sta[i]<<" ";
        }
        //cout<<"\n";
        ans=max(ans,s);
        return;
    }
    for(int i=x+1;i<=n;++i){
        if(a[i]<ans)continue;
        sta[p]=a[i];
        ++p;
        dfs(i,dep+1);
        --p;
    }
}
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //cout<<1;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    dfs(0,0);
    cout<<ans;
}
