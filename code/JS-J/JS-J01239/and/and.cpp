#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
//#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
#include<cstdio>
using namespace std;
using uint=unsigned;
template<typename T,typename K>
using hash_table=__gnu_pbds::cc_hash_table<T,K>;
int main(){
    #ifndef PSD
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    #endif // PSD
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<uint> v(n);
    array<vector<uint>,31> bit;
    bit.fill({});
    for(uint&i:v){
        cin>>i;
        uint i1=i;
        for(int j=30;j>=0;j--)if((i>>j)&1)
            bit[j].push_back(i);
    }
    if(m==1){
        cout<<*max_element(v.begin(),v.end());
        return 0;
    }
    hash_table<uint,int> s;
    size_t sz=0;
    uint ans=0;
    for(int i=30;i>=0;i--)if(bit[i].size()>=m){
        if(s.empty()){
            for(uint&j:bit[i])++s[j],++sz;
            ans=(1<<i);
        }
        else{
            hash_table<uint,int> nxt;
            size_t sz2=0;
            for(uint&j:bit[i])
                if(s.find(j)!=s.end())
                    ++nxt[j],++sz2;
            if(sz2>=m)
                ans|=(1<<i),s.swap(nxt),sz=sz2;
        }
    }
    cout<<ans;
    return 0;
}
