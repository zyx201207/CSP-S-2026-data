#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char c;
};
deque<node> dq;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    char l='A';
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        char y;
        cin>>x>>y;
        if(y==l)dq.back().a+=x;
        else{
            l=y;
            dq.push_back({x,y});
        }
    }
    while(dq.size()>1){
        auto x=dq.front(),y=dq.back();
        dq.pop_front();
        dq.pop_back();
        if(x.c==y.c){
            if(x.a>y.a)dq.push_front({x.a-y.a,x.c});
            else if(x.a<y.a)dq.push_back({y.a-x.a,y.c});
        }
        else{
            if(x.a>y.a){
                cnt+=y.a;
                dq.push_front({x.a-y.a,x.c});
            }
            else if(x.a<y.a){
                cnt+=x.a;
                dq.push_front({y.a-x.a,y.c});
            }
            else cnt+=x.a;
        }
    }
    cout<<cnt;
    return 0;
}
