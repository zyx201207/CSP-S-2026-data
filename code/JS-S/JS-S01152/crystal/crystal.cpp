#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll sum,ans=-1;
    //int ansl,ansr;
    for(int i=n;i>0;i--){
        sum=0;
        for(int j=i;j>0;j--){
            if(sum+(a[i]-a[j])>m){
                break;
            }
            if(ans<(i-j+1)){
                    ans=i-j+1;
                }
            sum+=a[i]-a[j];
           // cerr<<ansl<<" "<<ansr<<endl;
        }
    }
    cout<<ans;
    return 0;
}
/*
杜子德，我喜欢你很久了。
5 5
1 2 4 8 9
*/
