#include<bits/stdc++.h>
#define int long long
using namespace std;
deque<pair<int,char>> q;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,a;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        q.push_back({a,c});
    }
    int ans=0;
    while(q.size()!=1&&!q.empty()){
        int fa=q.front().first;
        char fc=q.front().second;
        int la=q.back().first;
        char lc=q.back().second;
        if(fc!=lc){

            if(fa>la){
                ans+=la;
                fa-=la;
                q.pop_back();
                q.pop_front();
                q.push_front({fa,fc});
                continue;

            }
            if(fa<la){
                ans+=fa;
                la-=fa;
                q.pop_back();
                q.pop_front();
                q.push_back({la,lc});
                continue;
            }
            if(fa==la){
                ans+=fa;
                q.pop_back();
                q.pop_front();
                continue;
            }
        }
        if(fc==lc){
            if(fa>la){
                fa-=la;
                q.pop_back();
                q.pop_front();
                q.push_front({fa,fc});
                continue;
            }
            if(fa<la){
                la-=fa;
                q.pop_back();
                q.pop_front();
                q.push_back({la,lc});
                continue;
            }
            if(fa==la){
                q.pop_back();
                q.pop_front();
                continue;
            }
        }
    }

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

