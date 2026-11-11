#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;
    char c;
    long long ans=0;
    deque<pair<int,char> >v;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        v.push_back(make_pair(x,c));
        //cout<<v.back().first;
    }
    while(v.size()>1){
        int plot=v.front().first;
        int die=v.back().first;
        if(v.front().second!=v.back().second){
            if(plot>die){
                ans+=die;
                v.pop_back();
                v.front().first-=die;
            }
            if(plot==die){
                ans+=plot;
                v.pop_back();
                v.pop_front();
            }
            if(plot<die){
                ans+=plot;
                v.pop_front();
                v.back().first-=plot;
            }
        }
        else{
            if(plot>die){
                v.pop_back();
                v.front().first-=die;
            }
            if(plot==die){
                v.pop_back();
                v.pop_front();
            }
            else{
                v.pop_front();
                v.back().first-=plot;
            }
        }
    }
    cout<<ans;
    return 0;
}
