#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005]={0},mx=-1e12,mid,sum=0,mb,mn=1e12,su=0;
bool check(ll x){
    ll ans=0;
    mb=0;
    for(int i=0;i<n;i++){
        if(x>=a[i]){
            ans+=x-a[i];
            mb++;
        }
    }
    //cout<<x<<" "<<mb<<endl;
    if(ans>m) return 0                          ;
    sum=max(mb,sum);
    return 1;
}
int main(){
   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
        mn=min(a[i],mn);
        su+=a[i];
    }
    su/=n;
    mid=su;
    ll l=mn,r=mx;
    while(l<=r){
        if(check(mid)){
            l=mid+1;
        }
        else r=mid-1;
        mid=(r+l)/2;
    }
   // cout<<mid<<endl;
    cout<<sum;
    return 0;
}
//kskbl 123456789                                                                                                !
//zdjd                                                                                               !
//yuan shen niu bi
//ai shang lei shen
//isolation
//wu bai nian lai,wo dou wang bu diao na ge yan shen,si zhi zhi zheng jiang xia bu si zu zhou de shi hou
//ta de yan zhong mei you bei min ye mei you kuai yi
//ming ming zhou wei dou shi qi qiu de ren me,si zhi zhi zheng yi jiu bu wei suo dong
//xian zai, ruo na wa,zheng shi wu!zheng shi ni de di ren!yu ren zhi yan!jie fang!ruo na wa!
//kskbl                                                                                               !
//zdjd                                                                                               !
//yuan shen niu bi
//ai shang lei shen
//isolation
//wu bai nian lai,wo dou wang bu diao na ge yan shen,si zhi zhi zheng jiang xia bu si zu zhou de shi hou
//ta de yan zhong mei you bei min ye mei you kuai yi
//ming ming zhou wei dou shi qi qiu de ren me,si zhi zhi zheng yi jiu bu wei suo dong
//xian zai, ruo na wa,zheng shi wu!zheng shi ni de di ren!yu ren zhi yan!jie fang!ruo na wa!
