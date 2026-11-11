#include<bits/stdc++.h>
#define maxn 500010
using namespace std;
int n,m,ans=-1,ans_point;
int a[maxn],f[maxn];
int get_forge(int l,int r){
    int cnt;
    cnt=a[r]-a[l-1];
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<' ';
    // }
    // cout<<"\n";
    int paid=m;
    for(int i=n;i>=1;i--){
        int cnt=1;
        if(ans>=i)break;
        if(ans>-1){
            if(paid<=get_forge(i-ans+1,i-ans+2))continue;
            cnt=ans-ans_point+i;
        }
        // if(i==4999){
        //     cout<<cnt<<' '<<paid<<' '<<get_forge(3800,4999)<<"\n";
        // }
        while(paid>0&&i-cnt>0){
            // if(i==4999){
            //     cout<<paid<<'w'<<get_forge(i-cnt+1,i)<<"\n";
            // }
            
            if((paid-=get_forge(i-cnt+1,i))>=0){
                cnt+=1;
                // cout<<paid<<'\n';
            }else{
                break;
            }
        }
        ans=max(ans,cnt);
        ans_point=i;
        paid+=a[i];
        cout<<i<<' '<<cnt<<"\n";
    }
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}