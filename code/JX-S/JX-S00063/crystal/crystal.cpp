#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[500050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
            int cnt=0;
            long long b=0;
        for(int j=1;j<=i;j++){
            if(b<m){
                if(b+abs(a[j]-a[i])>m)break;
                b+=abs(a[j]-a[i]);
                cnt++;
                if(cnt>ans)ans=cnt;
            }
        }
    }
    cout<<ans;
    return 0;
}
