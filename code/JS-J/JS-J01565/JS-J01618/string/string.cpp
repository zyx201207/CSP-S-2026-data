#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,ans;
deque<pair<int,char>> a;
char ch;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t>>ch;
        a.push_back({t,ch});
    }
    while(not a.empty()){
        if(a.size()<=1){
            break;
        }
        if(a.front().second!=a.back().second){
            ans+=min(a.front().first,a.back().first);
        }
        if(a.front().first<a.back().first){
            t=a.back().first-a.front().first;
            ch=a.back().second;
            a.pop_front();
            a.pop_back();
            a.push_back({t,ch});
        }else if(a.front().first>a.back().first){

            t=a.front().first-a.back().first;
            ch=a.front().second;
            a.pop_back();
            a.pop_front();
            a.push_front({t,ch});
        }else{
            a.pop_back();
            a.pop_front();
        }
    }
    cout<<ans<<"\n";
    return 0;
}
