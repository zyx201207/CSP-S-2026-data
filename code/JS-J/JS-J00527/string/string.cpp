#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int len;
    char ch;
}t[200005];
int n;
int ans=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].len;
        cin>>t[i].ch;
    }
    int l=1,r=n;
    int l_=t[1].len,r_=t[n].len,k=0;
    while(l<r){
        if(t[l].ch!=t[r].ch){
            ans+=min(l_,r_)-k;
        }
        k=min(l_,r_);
        if(l_<r_) l_+=t[++l].len;
        else if(l_>r_) r_+=t[--r].len;
        else{
            l_+=t[++l].len;
            r_+=t[--r].len;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
//g++ string.cpp -o string -std=c++11