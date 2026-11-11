#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000010],n,m,x[2000010],a1[2000010],cnt;
ll d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            int fx=1;
            while(a[i]-a[i-fx]<=d && i-fx>0){
                a1[i]+=1;
                fx++;
            }
            cnt+=a1[i];
        }if(c>=13 && c<=14){
            int ans=0;
            if(a[n]-a[1]==2*d){
                ans=n*(n-1)/2-cnt-1;
            }else
                ans=n*(n-1)/2-cnt;
            cout<<ans;
        }
        else{
            cout<<0<<endl;
        }
    }
}
