#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    deque<pair<char,int> >q;
    for(int i=0;i<n;i++){
        int g;
        char c;
        cin>>g>>c;
        q.push_back({c,g});
    }long long ans=0;
    while(q.size()>=2){
        pair<char,int> f=q.front(),t=q.back();
        q.pop_front();
        q.pop_back();
        if(f.first==t.first){
            if(f.second>t.second){
                int num=abs(f.second-t.second);
                q.push_front({f.first,num});
            }else if(f.second<t.second){
                int num=abs(f.second-t.second);
                q.push_back({t.first,num});
            }
        }else{
            ans+=min(f.second,t.second);
            if(f.second>t.second){
                int num=abs(f.second-t.second);
                q.push_front({f.first,num});
            }else if(f.second<t.second){
                int num=abs(f.second-t.second);
                q.push_back({t.first,num});
            }
        }
    }
    cout<<ans;
    return 0;
}
