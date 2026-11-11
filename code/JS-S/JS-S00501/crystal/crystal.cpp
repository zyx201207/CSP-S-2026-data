#include<bits/stdc++.h>
using namespace std;
#define LL long long

int n;
LL m;
LL a[500010];
int maxn=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long now=0;
    for(int i=2,j=1;i<=n;i++){
        now+=(a[i]-a[i-1])*(i-j);
        while(now>m){
            now-=a[i]-a[j];
            j++;
        }
        maxn=max(maxn,i-j+1);
    }
    cout<<maxn;
    return 0;
}