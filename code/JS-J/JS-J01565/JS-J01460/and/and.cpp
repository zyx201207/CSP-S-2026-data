#include<bits/stdc++.h>
using namespace std;
struct node{
    long long u;
    string s;
}a[200005];
bool cmp(node l1,node l2){
    if(l1.s.size()==l2.s.size()){
        return l1.s<l2.s;
    }
    return l1.s.size()<l2.s.size();
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i].u;
        long long k=a[i].u;
        while(k>0){
            a[i].s=char((k%2)+'0')+a[i].s;
            k/=2;
        }
    }
    sort(a+1,a+1+n,cmp);
    long long anss=0;
    for(long long i=1;i<=n;i++){
        if(a[i].s.size()!=a[i-1].s.size()&&i>m){
            long long k=pow(2,31)-1;
            for(long long j=i-1;j>=i-m;j--){
                k=(k&a[j].u);
            }
            anss=max(anss,k);
        }
    }
    long long ans=pow(2,31)-1;
    for(long long i=n;i>=n-m+1;i--){
        ans=(ans&a[i].u);
    }
    cout<<max(anss,ans);
    return 0;
}
