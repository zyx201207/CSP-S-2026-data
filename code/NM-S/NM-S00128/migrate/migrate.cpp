#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
typedef long long LL;
LL arr[N],c,t;
LL len[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        LL n,d;
        cin>>n>>d;
        int flag=1;
        for(LL i=0;i<n;i++){
            cin>>arr[i];
            if(i>2&&arr[i]-arr[i-1]!=arr[i-1]-arr[i-2])flag=0;
        }
        LL cha=arr[n-2]-arr[n-3];
        int num=d/cha;
        if(flag==0)cout<<0<<endl;
        else if(num==0||num==1||d>2)cout<<0<<endl;
        else{
            LL ans=0;
            for(int i=num+2;i<=n;i++){
                if((i-1)%num!=0)ans+=n-i+1;
            }
            cout<<ans<<endl;
        }
    }
}
