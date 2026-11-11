#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct pt{
    long long len;
    string  c;
};
long long n,ans=0;
deque<pt>q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long pre;
        string x;
        cin>>pre>>x;
        q.push_back({pre,x});
    }
    while(!q.empty()){
        if(q.size()==1) break;
        pt l=q.front(),r=q.back();
        q.pop_front();
        q.pop_back();
        if(l.c!=r.c){
            ans+=min(l.len,r.len);
        }
        if(l.len<r.len){
            q.push_back({r.len-l.len,r.c});
        }
        else if(r.len<l.len){
            q.push_front({l.len-r.len,l.c});
        }
    }
    cout<<ans;
    return 0;
}
