#include<bits/stdc++.h>
using namespace std;
const  long long maxn=2e5+5;
long long lowbit(long long x){return x&-x;}
struct node{
    long long x,y;
};
bool cmp(const node&a,const node&b){
    if(a.y!=b.y) return a.y>b.y;
    return a.x>b.x;
}
int n,m;
node a[maxn];
long long cnt[maxn];
long long sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].y=lowbit(a[i].x);
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1].x;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        cnt[a[i].y]++;
    }
    for(long long i=1;i<=n;i++){

    }
    return 0;
}
