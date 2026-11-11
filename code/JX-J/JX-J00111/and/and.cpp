#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;
    int f;
};
int n,m,ans;
node a[200005];
bool cmp(node l,node r){
    if(l.f==r.f) return l.x>r.x;
    else return l.f>r.f;
}
int f(int x){
    int cnt=0;
    while(x){
        x=x&(x-1);
        cnt++;
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].f=f(a[i].x);
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1].x;
    for(int i=2;i<=m;i++){
        ans&=a[i].x;
    }
    cout<<ans;
    return 0;
}
