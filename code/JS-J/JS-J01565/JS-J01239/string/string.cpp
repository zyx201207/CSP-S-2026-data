#include<iostream>
#include<vector>
#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
using plc=pair<long long,char>;
int main(){
    #ifndef PSD
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    #endif // PSD
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<plc> v;
    string s;
    long long sum=0;
    while(n--){
        long long a;
        char c;
        cin>>a>>c,sum+=a;
        if(v.empty()||v.back().second!=c)v.emplace_back(a,c);
        else v.back().first+=a;
    }
    /*
    for(auto&i:v)s.append(string(i.first,i.second));
    long long ans=0;
    for(int i=0;i<s.size()/2;i++)ans+=s[i]!=s[s.size()-i-1];
    cout<<ans<<'\n',ans=0;
    */
    long long pre=0,ans=0;
    bool over=false;
    vector<plc> l,r;
    for(auto&i:v){
        if(over)r.push_back(i);
        else if(pre+i.first>sum/2){
            if(sum&1)--i.first;
            if(i.first){
                if(sum/2-pre)
                    l.emplace_back(sum/2-pre,i.second);
                if(i.first-(sum/2)+pre)
                    r.emplace_back(i.first-(sum/2)+pre,i.second);
            }
            over=(pre+i.first>sum/2),pre+=i.first;
        }
        else{
            l.push_back(i);
            pre+=i.first;
        }
    }
    reverse(r.begin(),r.end());
    while(!l.empty()&&!r.empty()){
        auto a=l.back(),b=r.back();
        int f=(a.second!=b.second);
        if(a.first<b.first)
            ans+=f*a.first,r.back().first-=a.first,l.pop_back();
        else if(a.first==b.first)
            ans+=f*a.first,l.pop_back(),r.pop_back();
        else ans+=f*b.first,l.back().first-=b.first,r.pop_back();
    }
    cout<<ans;
    return 0;
}
