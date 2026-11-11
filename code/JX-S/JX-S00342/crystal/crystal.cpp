#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long INF=0x3f3f3f3f;
long long n,m;
long long a[N];
long long d[N],d1[N];
long long sum=0,num=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    for(int i=1;i<n;i++){
        if(sum>m){
            sum-=d[i-1];
            num--;
            break;
        }
        sum+=d[i];
        d[i+1]+=d[i];
        num++;
    }
    cout<<num;
    return 0;
}
