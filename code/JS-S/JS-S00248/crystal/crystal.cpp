#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N],b[N],p,c,maxn=0;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    for(long long i=1;i<n;i++){
        p=0;
        c=1;
        long long j=i;
        while(p<=m && j<n){
            if(p+b[j]*(j-i+1)<=m){
                p+=(b[j]*(j-i+1));
                c++;
                j++;
            }
            else break;
        }
        maxn=max(maxn,c);
    }
    if(maxn==1) maxn=0;
    cout<<maxn<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
