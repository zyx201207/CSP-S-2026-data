#include <bits/stdc++.h>
using namespace std;
int mins;
long long a[100005];
long long tmp[100005];
bool comp(long long a,long long b){
    int ax=abs(a-mins),bx=abs(b-mins);
    if(ax<bx && ax>mins) return true;
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tmp[i]=a[i];
    }
    for(int i=0;i<n;i++){
        mins=a[i];
        sort(tmp,tmp+n,comp);

    }
    int cnt=0;
    for(int i=1;i<n-1;i++){
        m-=(a[0]-a[i]);
        cnt++;
    }
    cout<<cnt;

    return 0;
}
