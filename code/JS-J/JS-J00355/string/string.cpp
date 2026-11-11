#include <bits/stdc++.h>
using namespace std;
struct block{
    long long len;
    char c;
    long long index;
    block(long long a,char b,long long i):len(a),c(b),index(i){};
};
int main(){
    #define int long long
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,l=0;
    cin>>n;
    vector<block> blocks;
    for(int i=0;i<n;i++){
        int num;
        char c;
        cin>>num>>c;
        blocks.emplace_back(num,c,i);
        l+=num;
    }
    int ans=0;
    for(block curl=blocks[0],curr=blocks.back();curl.index!=curr.index;){
        if(curl.c==curr.c){
            if(curl.len>curr.len){
                curl.len=curl.len-curr.len;
                curr=blocks[curr.index-1];
            }
            else{
                curr.len=curr.len-curl.len;
                curl=blocks[curl.index+1];
            }
        }
        else{
            if(curl.len>curr.len){
                ans+=curr.len;
                curl.len=curl.len-curr.len;
                curr=blocks[curr.index-1];
            }
            else{
                ans+=curl.len;
                curr.len=curr.len-curl.len;
                curl=blocks[curl.index+1];
            }
        }
        
    }
    cout<<ans<<endl;
    #undef int
    return 0;
}