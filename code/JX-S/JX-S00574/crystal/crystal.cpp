#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool b=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) b=false;
    }
    if(b){
        long long c=1;
        long long d=0;
        while(m&&m>=c){
            m-=c;
            c+=(c+1);
            d++;
        }
        cout<<d+1;
        return 0;
    }
    sort(a+1,a+n+1);
    int sum=-INT_MAX;
    for(int i=n;i>=1;i--){
            int e=m;
            int num=1;
            while(e){
                num++;
                e-=(a[i]-a[i-num]);
            }
            cout<<num<<" ";
            sum=max(sum,num);
    }
    cout<<sum;
    //quxiao zhushi
    return 0;
}
