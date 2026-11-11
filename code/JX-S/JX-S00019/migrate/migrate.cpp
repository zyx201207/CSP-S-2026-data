#include<bits/stdc++.h>
using namespace std;
int c,t,n;bool flag=true;
long long d;int pos=0;
long long ans;
long long a[2000005];
long long cha[2000005];
int f(int l,int r){
    int mid=(l+r)>>1;
    if(l>r){
        return min(l,n);
    }
    if(cha[mid]-cha[pos]<=d){
        f(mid+1,r);
    }else{
        f(l,mid-1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            cha[i]=a[i]-a[0];
        }
        while(pos<n){
            int tot=f(1,n);
            if(pos){
                ans+=tot-pos;
            }
            pos=tot;

        }
        cout << ans << '\n';
        pos=0;
        ans=0;
    }
    return 0;
}
