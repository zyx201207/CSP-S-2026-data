#include<bits/stdc++.h>
#define int long long
using namespace std;
int nfu,T,n,d,a;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >>nfu>>T;
    while(T--){
        vector<int>tt;
        bool atest=1;
        cin >>n>>d;
        for(int i=0;i<n;i++){
            cin >>a;
            tt.push_back(a);
        }
        for(int i=2;i<n;i++){
            if(tt[i]-tt[i-1]!=tt[i-1]-tt[i-2])atest=0;
        }
        if(atest){
            int c=tt[1]-tt[0];
            if(d<=c){
                cout <<0<<endl;
                atest=0;
            }
            else {
                for(int i=2;2*i-1<n;i++){
                    if(d>=i*c&&d<i*c+c){
                        cout <<n-2*i+1<<endl;
                        atest=0;
                        break;
                    }
                }
            }
            if(atest)cout <<0<<endl;
        }
        else {
            //sort(tt.begin(),tt.end())
            int ttans=0;
           priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>run;
           vector<vector<int>>ans,cnt;
           ans.resize(n+1,vector<int>(n+1));
           cnt.resize(n+1,vector<int>(n+1));
           for(int s=0;s<n;s++){
                bitset<1145141>vis;
                vis[s]=1;
                ans[s][s]=0;
                cnt[s][s]=1;
                run.push({0,s});
                while(!run.empty()){
                    auto p=run.top();
                    run.pop();
                    if(vis[p.second])continue;
                    vis[p.second]=1;
                    for(int i=p.second+1;i<n;i++){
                        int c=tt[i]-tt[p.second];
                        if(c>d)break;
                        if(ans[s][i]>p.first+1){
                            ans[s][i]=p.first+1;
                            cnt[s][i]=cnt[s][p.second];
                            run.push({ans[s][i],i});
                        }
                        else if(ans[s][i]==p.first+1){
                            cnt[s][i]+=cnt[s][p.second];
                        }
                    }
                }
           }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(cnt[i][j]==2)ttans++;
                }
            }
            cout <<ttans<<endl;
        }
    }
    return 0;
}
