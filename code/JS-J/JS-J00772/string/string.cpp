#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,k,all;
deque<pair<int,char>>q;
vector<pair<int,char>>v;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        char c;
        cin>>x>>c;
        all+=x;
        q.push_back({x,c});
    }
    while(!q.empty()){
        k++;
        if(q.size()==1)
            break;
        v.clear();
        int x=q.front().first;
        char c=q.front().second;
        int sum=x,cnt=0,p;
        cnt=all-sum;
        sum=min(sum,cnt);
        p=sum;
        while(sum!=0){
            int y=q.back().first;
            char d=q.back().second;
            if(sum>=y){
                v.push_back({y,d});
                if(!q.empty())
                    q.pop_back();
                sum-=y;
                all-=y;
            }
            else if(sum<y){
                v.push_back({sum,d});
                q.back().first-=sum;
                all-=sum;
                sum=0;
            }

        }
        for(int i=0;i<v.size();i++){
            if(c!=v[i].second){
                //cout<<c<<' '<<v[i].second<<endl;
                ans+=v[i].first;
            }
        }
        if(p==x)
            q.pop_front();
        if(p<x)
            q.front().first-=p;
    }
    cout<<ans<<endl;
}
