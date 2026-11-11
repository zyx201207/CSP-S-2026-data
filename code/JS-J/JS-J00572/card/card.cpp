#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt[N];
bool c[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n>=1000){
        for(int i=1;i<=n;i++){
            cnt[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<" ";
        }
        return 0;
    }
    for(int t=1;t<=n;t++){
        memset(c,0,sizeof(c));
        vector<int> b;
        b.clear();
        for(int i=t;i<=n;i++){
            if(!b.empty())for(int j=0;j<b.size();j++){
                if(b[j]==a[i]){
                    for(int z=b.size();z>=b.size()-1-j;z--)b.pop_back();
                    break;
                }
            }
            b.push_back(a[i]);
        }
        for(auto i:b)c[i]=1;
        for(int i=1;i<=m;i++)if(c[i])cnt[i]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
