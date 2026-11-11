#include<bits/stdc++.h>
using namespace::std;
int n,m;
const int N=200005;
long long a[N];
int ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    sort(a+1,a+n+1);
    if(n==m){
        int x = a[n] & a[1];
        cout<<x;
        return 0;
    }
    else if(m==1){
        cout<<a[n];
        return 0;
    }
    for(int r=n;r>=1;r--){
        int l=1,maxn=-1;
        while(l <=n){
            int x=a[r] & a[l];
            maxn=max(maxn,x);
            l++;
        }
        ans=max(ans,maxn);
    }
    cout <<ans;
    return 0;
}
