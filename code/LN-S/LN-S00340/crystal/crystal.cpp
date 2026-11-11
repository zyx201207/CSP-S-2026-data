#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
int f(int x,int it){
    int sum=0;
    int i=m;
    while(i>0&&it>0){
        i-=(x-a[it]);
        it--;
        if(i>=0) sum++;
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long num=a[2]-a[1];
    for(int i=3;i<=n;i++)
        if(a[i]-a[i-1]!=num)flag=false;
    if(flag){
        int ans=1;
        int i=1;
        while(m>0){
            m-=num*i;
            i++;
            if(m>=0) ans++;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    long long max_=-1e18;
    for(int i=a[1];i<=a[n];i++){
        int it;
        for(int j=1;j<=n;j++){
            if(a[j]>i){
                it=j-1;
                break;
            }
        }
        long long sum=f(i,it);
        if(sum<=m)
            max_=max(max_,sum);
    }
    cout<<max_;
    return 0;
}
