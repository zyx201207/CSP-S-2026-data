#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    deque<pair<long long,char>>s;
    for(long long i=0;i<n;i++){
        pair<long long,char>a;
        cin>>a.first>>a.second;
        s.push_back(a);
    }
    while(!s.empty()){
        if(s.size()==1){
            break;
        }
        if(s[0].second!=s[s.size()-1].second){
            if(s[0].first>s[s.size()-1].first){
                ans+=s[s.size()-1].first;
                s[0].first-=s[s.size()-1].first;
                s.pop_back();
            }
            else if(s[0].first==s[s.size()-1].first){
                ans+=s[0].first;
                s.pop_front();
                s.pop_back();
            }
            else{
                ans+=s[0].first;
                s[s.size()-1].first-=s[0].first;
                s.pop_front();
            }
        }
        else{
            if(s[0].first>s[s.size()-1].first){
                s[0].first-=s[s.size()-1].first;
                s.pop_back();
            }
            else if(s[0].first==s[s.size()-1].first){
                s.pop_front();
                s.pop_back();
            }
            else{
                s[s.size()-1].first-=s[0].first;
                s.pop_front();
            }
        }
    }
    cout<<ans;
    return 0;
}
