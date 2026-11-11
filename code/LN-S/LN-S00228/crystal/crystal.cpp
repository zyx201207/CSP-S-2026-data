#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[10005][10005];
int main(){
    freopen("crystal.in",r,stdin);
    freopen("crystal.out",w,stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            b[i][j]=a[i]-a[j];
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long lin_cnt=0;
        for(int j=1;j<=i;j++){
            lin_cnt+=b[i][j];
            if(lin_cnt>m) continue;
        }
        if(lin_cnt>m) continue;
        ans=i;
    }

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
