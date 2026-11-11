#include<bits/stdc++.h>
using namespace std;
long long n,tot;
struct s{
    long long x;
    char c;
};
deque<s> dq;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        long long x;char c;
        cin>>x>>c;
        dq.push_back({x,c});
    }
    s t1=dq.front(),t2=dq.back();
    dq.pop_front();dq.pop_back();
    while(!dq.empty()){
        long long t=min(t1.x,t2.x);
        t1.x-=t;t2.x-=t;
        if(t1.c!=t2.c) tot+=t;
        if(t1.x==0){
            t1=dq.front();
            dq.pop_front();
        }
        if(t2.x==0){
            t2=dq.back();
            dq.pop_back();
        }
    };
    long long t=min(t1.x,t2.x);
    if(t1.c!=t2.c) tot+=t;
    cout<<tot;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
