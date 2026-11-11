#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],l,r=99999999,s,t,mid;
bool f(long long x,long long y){
    if(x>n||x>y) return 0;
    return (x-1)*a[y]-(b[y-1]-b[y-x])<=m;
}
//map<long long,int>b;
//struct u{
//    long long sz,sl;
//};
//vector<u>c;
//long long f(long long x){
//    int y=1;
//    while(x>2) y++,x=(x-(x%2?1:2))/2;
//    return y;//
//}
//bool pd(){
//    for(auto i:b) if(i.second>1) return 0;
//    return 1;
//}
//bool p(long long x){
//    for(int i=0;i<=t-x;i++) if(c[i+x-1].sz-c[i].sz-x+2<=m) return 1;
//    return 0;
//}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];//b[a[i]]++;
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++) b[i]=a[i]+b[i-1];
    for(long long i=1;i<=n;i++){
        l=0,r=999999;
        while(l<=r){
            mid=(l+r)/2;
            if(f(mid,i)) t=mid,l=mid+1;
            else r=mid-1;
        }
        s=max(s,t);
    }
    cout<<s<<endl;
    //for(auto it:b) c.push_back({it.first,f(it.second)});
    //while(pd()){
    //    b.clear();
    //    for(u i:c) for(int j=i.sz;j<i.sz+i.sl;j++) b[j]++;
    //    if(pd()) break;
    //    for(auto it:b) c.push_back({it.first,f(it.second)}),cout<<it.first<<' '<<it.second<<endl;
    //}
    //t=c.size();
    //while(l<=r){
    //    mid=(l+r)/2;
    //    if(p(mid)) s=mid,l=mid+1;
    //    else r=mid-1;
    //}
    //cout<<s<<endl;
    return 0;
}
