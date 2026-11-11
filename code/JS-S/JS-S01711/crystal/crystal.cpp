#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500010],l=1,r=2,len=1,cnt=0,mx=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cnt=a[r]-a[l];
    while(r<=n){
        if(cnt<=m){
            r++;
            len=r-l+1;
            cnt+=(a[r]-a[r-1])*(r-l);
            if(cnt<=m){
                mx=max(len,mx);
            }
        }else{
            l++;
            cnt-=(a[r]-a[l-1]);
        }
    }
    cout<<mx;
    return 0;
}
