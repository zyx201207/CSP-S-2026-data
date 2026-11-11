#include<bits/stdc++.h>
using namespace std;
int n,m,pos=-1,ans,a[220000],cnt[33];
bool bit[220000][33];
vector<int>cho,rea;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        for(int j=30;j>=0;--j){
            int res=a[i]>>j&1;
            bit[i][j]=res;
            cnt[j]+=res;
        }
    }
    for(int i=30;i>=0;--i){
        if(cnt[i]>=m){
            pos=i;
            break;
        }
    }
    if(pos<0){
        cout<<0<<endl;
    }
    ans=1<<pos;
    for(int i=1;i<=n;++i){
        if(bit[i][pos]){
            cho.push_back(i);
        }
    }
    for(int i=pos-1;i>=0;--i){
        int cntt=0;
        bool flag=0;
        rea.clear();
        for(auto j:cho){
            if(bit[j][i]){
                rea.push_back(j);
                ++cntt;
            }
        }
        if(cntt>=m){
            ans+=1<<i;
            cho=rea;
        }
    }
    cout<<ans<<endl;
    return 0;
}
