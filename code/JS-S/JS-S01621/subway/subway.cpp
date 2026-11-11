#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[5000005ll];
struct station{
    long long name;
    long long taketime;
    long long mouthtime;
};
vector<station> sub[505ll];
vector<long long> sta[5000005ll];
queue<pair<pair<long long,long long>,pair<long long,long long> > > que;
vector<long long> b;
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        long long x;
        cin>>x;
        a[i]=x;
    }
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        for(int j=1;j<=x;j++){
            long long y,t;
            cin>>y>>t;
            sub[i].push_back({y,t,a[y]});
            sta[y].push_back(i);
        }
    }
    for(int i=1;i<=q;i++){
        long long x,y;
        cin>>x>>y;
        bool flag=0;
        long long ans=a[x]+a[y],minans=100000000000ll;
        for(auto v1:sta[x]){
            long long ss=0;
            bool flag1=0;
            for(auto v2:sub[v1]){
                if(v2.name==x){
                    ss+=v2.taketime;
                }
                if(v2.name==y){
                    flag=1;
                    flag1=1;
                    ss+=v2.taketime;
                }
            }
            if(ss+ans<minans&&flag1){
                minans=ss+ans;
            }
        }
        if(flag){
            b.push_back(minans);
            continue;
        }
        que.push(make_pair(make_pair(x,0),make_pair(0,a[x])));
        while(1){
            pair<pair<long long,long long>,pair<long long,long long> > fa=que.front();
            que.pop();
            if(fa.second.first!=0){
                que.push(make_pair(make_pair(fa.first.first,fa.first.second),make_pair(fa.second.first-1,fa.second.second+1)));
                continue;
            }
            if(fa.first.first==y){
                b.push_back(fa.second.second+a[fa.first.first]);
                break;
            }
            for(auto v1:sta[fa.first.first]){
                long long xx;
                for(auto v2:sub[v1]){
                    if(v2.name==fa.first.first){
                        xx=v2.taketime;
                        continue;
                    }
                    que.push(make_pair(make_pair(v2.name,v2.taketime),make_pair(v2.taketime+xx,fa.second.second)));
                }
            }
        }
    }
    for(auto v:b){
        cout<<v<<endl;
    }
    return 0;
}
