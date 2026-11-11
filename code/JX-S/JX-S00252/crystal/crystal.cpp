#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    bool f=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2&&a[i]-a[i-1]!=a[2]-a[1])f=false;
    }

    if(f==true){
        int cha=a[2]-a[1];
        for(int i=1;i<n;i++){
            if(m<i*cha){
                cout<<i;
                return 0;
            }
            m-=i*cha;
        }
        cout<<n;
        return 0;
    }

    sort(a+1,a+n+1);

    int ans=0;
    for(int i=1;i<=n;i++){
        while(i+1<=n&&a[i+1]==a[i])i++;

        long long h=a[i];

        long long sum=0;
        int p=i-1;
        while(p>=1){
            if(sum+(h-a[p])<=m){
                sum+=(h-a[p]);
                p--;
            }else{
                break;
            }
        }
        ans=max(ans,i-p);
    }
    cout<<ans;
    return 0;
}
