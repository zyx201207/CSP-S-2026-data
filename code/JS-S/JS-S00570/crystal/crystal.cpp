#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5*100010],num,num2,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long l=1;
    a[0]=a[1];
    for(int i=1;i<=n;i++){
        ans=max(i-l+1,ans);
        while(num2+(a[i]-a[i-1])*(i-l+1)>m){
            num2-=num;
            num-=(a[l+1]-a[l]);
            l++;
        }
        num+=(a[i]-a[i-1]);
        num2+=(a[i]-a[i-1])*(i-l+1);
        //cout<<num2<<" "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/

