#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long cnt=1;
    long long mx=0;
    long long j=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i!=j&& m>=abs(a[j]-a[i])*cnt){
                m-=abs(a[j]-a[i])*cnt;
                cnt++;
                j++;
            }
            mx=max(mx,cnt);
        }
    }
    cout<<mx;
}
