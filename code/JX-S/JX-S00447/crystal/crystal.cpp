#include<bits/stdc++.h>
using namespace std;
int n,ans=1;long long ans2,m,a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int f=1,f2=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2])&&i>1)f=0;
    }
    if(f==1&&f2==0){
        for(long long i=sqrt(m/abs(a[2]-a[1]));;i++){
            if((i+1)*i/2>m/(a[2]-a[1])){
                ans2=i-1;
                break;
            }
        }
        cout<<ans2;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        int m2=m;
        for(int j=i-1;;j--){
            if(m2-a[i]+a[j]<0||j==1){
                ans=max(i-j,ans);
                break;
            }
            m2+=a[j]-a[i];
        }
    }
    cout<<ans;
    return 0;
}
