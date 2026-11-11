#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,cost,ans=1,l,r;
vector<int>tt;
deque<int>run;
bool cmp(int a,int b){
    return a<b;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for(int i=0;i<n;i++){
        cin >>a;
        tt.push_back(a);
    }
    sort(tt.begin(),tt.end(),cmp);
    cost=0;
    r=1;
    run.push_back(tt[0]);
    while(r<n){
        if(run.empty()){
            r++;
            run.push_back(tt[l]);
            continue;
        }
        int c=tt[r]-run.front();
        c*=run.size();
        if(cost+c<=m){
            run.push_front(tt[r]);
            cost+=c;
            r++;
        }
        else if(l<r){
            run.pop_back();
            cost-=run.front()-tt[l];
            l++;
        }
        ans=max(ans,r-l);
    }
    cout <<ans;
    return 0;
}
