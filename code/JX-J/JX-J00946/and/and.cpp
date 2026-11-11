#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m;
long long a[N];
struct node{
    long long sum,cnt;
};
vector<node> q;
long long maxx;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(m==n) a[1]&=a[i];
        if(m==1) maxx=max(maxx,a[i]);
    }
    if(m==n){
        cout<<a[1];
        return 0;
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    if(m==2){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
        return 0;
    }
    q.push_back({a[1],1});
    for(int i=2;i<=n;i++){
        int len=q.size();
        for(int j=0;j<len;j++){
            node now=q[j];
            if(now.sum&a[i]==0 || now.cnt==m) continue;
            q.push_back({now.sum&a[i],now.cnt+1});
        }
        q.push_back({a[i],1});
    }
    int len=q.size();
    for(int j=0;j<len;j++){
        node now=q[j];
        if(now.cnt==m){
            maxx=max(maxx,now.sum);
        }
    }
    cout<<maxx;
    return 0;
}
