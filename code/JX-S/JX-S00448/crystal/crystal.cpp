#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,a[500010],minn,maxn,num,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    minn=a[1],maxn=a[n];

    for(long long i=1;i<=n;i++){
            num=0;
        for(long long j=i;j>=1;j--){
            num+=(a[i]-a[j]);
            if(num<=m){
                ans=max(ans,i-j+1);
            }
        }
    }

    cout << ans;




    return 0;
}

