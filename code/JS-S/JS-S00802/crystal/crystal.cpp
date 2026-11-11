#include<bits/stdc++.h>
#define int long long
const int N=5e5+5;
int a[N];
using namespace std;
int cmp(int x,int y){
    return x<y;
}
int go(int x,int y){
    int ans=0;
    while(1){
        if((ans+2)*(ans+1)*x>=2*y) break;
        else ans++;
    }
return ans+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    int cha=a[1]-a[0];
    bool flag=true;
    for(int i=1;i<n-1;i++){
        if(!(a[i]+cha==a[i+1])){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<go(cha,m)<<endl;
        return 0;
    }
    int ans=1;
    for(int i=1;i<n;i++){
        int j=i-1,mr=m,cnt=1;
        while(mr>=0 && j>=0){
            if(a[i]-a[j]<=mr){
                cnt++;
                mr-=(a[i]-a[j]);
            }
            else break;
            j--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
return 0;
}
