#include<bits/stdc++.h>
using namespace std;
long long pow_2[35];
int n,m,a[200005],b[200005];
vector<int> t[35];
vector<int> q;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long flag = 1;
    pow_2[0] = 1;
    for(int i = 1;i<=31;i++){
        flag*=2;
        pow_2[i] = flag;
    }
    cin>>n>>m;
    int maxk = -1;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        b[i] = a[i];
        for(int k = 31;k>=0;k--){
            if(b[i]>=pow_2[k]){
                t[k].push_back(a[i]);
                b[i]-=pow_2[k];
                maxk = max(maxk,k);
            }
        }
    }
    int ans = 0;
    bool f = 1;
    int time = 0;
    for(int i = maxk;i>=0;i--){
        if(t[i].size() == m){
            int fans = 0;
            bool f1 = 0,f2 = 0;
            if(q.empty()) f2 = 1;
            for(int k = 0;k<t[i].size();k++){
                if(k == 0){
                    for(int j:q){
                        if(t[i][k] == j&&!f1){f1 = 1;break;}
                    }
                    if(!f1&&!f2) break;
                    fans = t[i][k];
                    continue;
                }
                for(int j:q) if(t[i][k] == j&&!f1){f1 = 1;break;}
                if(!f1&&!f2) break;
                fans&=t[i][k];
            }
            ans = max(ans,fans);
        }
        else if(t[i].size()>m){
            if(time == 0){
                q = t[i];
            }
            if(q!=t[i]) f = 0;
            if(f){
                ans|=pow_2[i];
                q = t[i];
                time++;
            }
        }
    }
    cout<<ans;
    return 0;
}
