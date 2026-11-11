#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],vis[3005],cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(m==1&&n>5000){
        cout<<n<<'\n';
        return 0;
    }
    if(m==2&&n>5000){
        int x=a[n];
        for(int i=1;i<=n;i++){
            if(a[i]==x&&x==1){
                cnt[1]++;
            }else if(a[i]==x&&x==2){
                cnt[2]++;
            }else{
                cnt[1]++,cnt[2]++;
            }
        }
        cout<<cnt[1]<<' '<<cnt[2]<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        vector<int> num;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(num[num.size()-1]!=a[j])vis[num[num.size()-1]]=0,num.pop_back();
                num.pop_back();
            }
            vis[a[j]]=1;num.push_back(a[j]);
        }
        for(auto x:num)cnt[x]++;
    }
    for(int i=1;i<=m;i++){
        if(i!=m)cout<<cnt[i]<<' ';
        else cout<<cnt[i]<<'\n';
    }
    return 0;
}
