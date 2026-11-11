#include <bits/stdc++.h>

using namespace std;


long long a[1000009],q[1000009],ans;
int main()
{
   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,m;
    cin>>n>>m;
q[1]=0;
long long minn=999999999;

    for(long long i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);

    }


    if(minn<0){
        for(long long i=1;i<=n;i++){

            a[i]+=abs(minn);

           // cout<<"Q!"<<endl;

        }
    }
sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++){
        q[i]=(a[i]-a[i-1])*(i-1)+q[i-1];

       // cout<<"Q!"<<i<<endl;

    }
    for(long long i=n;i>=1;i--){

        if(q[i]<=m){
            cout<<i;
            return 0;
        }
    }

    return 0;
}
