#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d;
ll x[2000006],ans;
vector<int> vp[2000006];
int lb(int y){
    int l=0,r=n,an;
    while(l<r){
        int mid=l+r>>1;
        if(x[mid]<=y){
            l=mid+1;
            an=mid;
        }else r=mid;
    }
    return an;
}
int ub(int y){
    int l=0,r=n,an;
    while(l<r){
        int mid=l+r>>1;
        if(x[mid]>=y){
            r=mid;
            an=mid;
        }else l=1+mid;
    }
    return an;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n-1;i++){
            int p=lb(x[i]+d);
            for(int j=i+1;j<n;j++){
                while(p<j){
                    vp[i].push_back(p);
                    p=lb(x[p]+d);
                }

            }
            p=ub(x[n-i-1]-d);
            for(int j=n-i-2;j>=0;j--){
                while(p>j){
                    vp[n-i-1].push_back(p);
                    p=ub(x[p]-d);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if((int)vp[i].size()!=j-i-1 || (int)vp[j].size()!=j-i-1) continue;
                int cnt=0;
                for(int k=0;k<j-i-1;k++){
                    if(vp[i][k]!=vp[j][k]){
                        cnt++;
                    }
                }
                if(cnt==1) ans++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
