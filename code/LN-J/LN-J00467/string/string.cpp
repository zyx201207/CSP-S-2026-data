#include<bits/stdc++.h>
using namespace std;
using in=long long;
unordered_map<char,vector<pair<in,in>>>mp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    in n,x,sum=0,ans=0;
    char a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>a;
        mp[a].push_back({ans+1,ans+x});
        ans+=x;
    }
    in b=ans/2;
    for(in i=1;i<=b;i++){
        char z,y;
        for(in j=0;j<26;j++){
            for(auto num:mp[(char)(j+'a')]){
                if(num.first<=i&&num.second>=i){
                    z=(char)(j+'a');
                }
                if(num.first<=i+(ans+1)/2&&num.second>=i+(ans+1)/2){
                    y=(char)(j+'a');
                }
            }
        }
        if(z!=y)sum++;
    }
    cout<<sum;
}
