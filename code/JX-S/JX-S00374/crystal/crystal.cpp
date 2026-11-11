#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans,k;
queue<long long>l,r;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int mid=(1+n)>>1;
    for(int i=mid;i>=1;i--){
        l.push(a[i]);
    }
    for(int i=mid+1;i<=n;i++){
        r.push(a[i]);
    }
    long long top=a[mid];
    while(!l.empty()&&!r.empty()&&m){
        if(top-l.front()>(r.front()-top)*ans){
            if(m>=(r.front()-top)*ans){
                m-=(r.front()-top)*ans;
                ans++;
                top=r.front();
                r.pop();
            }else{
                break;
            }
        }else{
            if(m>=top-l.front()){
                ans++;
                m-=(top-l.front());
                l.pop();
            }else{
                break;
            }
        }
    }
    while(!l.empty()&&m){
        if(m>=top-l.front()){
            ans++;
            m-=(top-l.front());
            l.pop();
        }else{
            break;
        }
    }
    while(!r.empty()&&m){
        if(m>=(r.front()-top)*ans){
            m-=(r.front()-top)*ans;
            ans++;
            top=r.front();
            r.pop();
        }else{
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}
