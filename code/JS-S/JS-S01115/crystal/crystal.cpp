#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int cnt,ans;
long long num,now;
int l;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    now=a[1];
    cnt=1;
    l=1;
    for(int i=2;i<=n;i++){
        num+=(a[i]-now)*cnt;
        now=a[i];
        cnt++;
        while(num>m){
            num-=now-a[l];
            l++;
            cnt--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
