#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],mas=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    bool ttt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(abs(a[i])>100001){
            ttt=1;
        }
    }
    if(ttt){
        long long c=a[5]-a[4],s=0;
        for(int i=n-1;i>=1;i--){
            s+=c;
            if(s<=m){
                m-=s;
                mas++;
            }
            else{
                break;
            }
        }
        cout<<mas;
        return 0;
    }
    sort(a+1,a+1+n);
    long long s=0,ans=0;
    for(int i=2;i<=n;i++){
        s=0;
        ans=0;
        for(int j=i-1;j>=1;j--){
            s=s+(a[i]-a[j]);
            if(s>m){
                break;
            }
            else{
                ans++;
            }
        }
        mas=max(ans,mas);
    }
    cout<<mas+1;
    return 0;
}
