#include<bits/stdc++.h>
using namespace std;
int n,m,d[35],st=0;
struct Auv{
    int num,ty;
}a[200005];
bool comp(Auv x,Auv y){
    if(x.ty==y.ty)
        return x.num>y.num;
    return x.ty>y.ty;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        a[i].ty=(a[i].num==0)?0:(floor(log2(a[i].num))+1);
        d[a[i].ty]++;
    }
    sort(a+1,a+n+1,comp);
    for(int i=31;i>=1;i--){
        if(d[i]>=m){
            st++;
            break;
        }
        st+=d[i];
    }
    if(st>=n)
        st=1;
    int ans=a[st].num;
    for(int i=st+1;i<m+st;i++)
        ans&=a[i].num;
    cout<<ans;
    return 0;
}