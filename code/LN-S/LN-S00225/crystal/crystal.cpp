#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500010],ans,ans2;
struct f{
    long long x,y;
}b[500010];
bool cmp(f a,f b){
    return a.x>b.x;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++){
        b[i].x=a[i+1]-a[i];
        b[i].y=i;
    }
    for(int i = 1;i<n;i++){
        if(m-(b[i].x*(1<<(i-1)))>=0){
            ans2++;
            m-=(b[i].x*(1<<(i-1)));
        }else continue;
    }
    sort(b+1,b+n,cmp);
    for(int i = 1;i<n;i++){
        if(m-(b[i].x*(1<<(i-1)))>=0){
            ans++;
            m-=(b[i].x*(1<<(i-1)));
        }else continue;
    }
    cout<<max(ans,ans2)+1;
    return 0;
}
