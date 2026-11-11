#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll a[500010],s[500010];ll n,m;
/*bool check(int l,int r){
    return (a[r]*(r-l)-(s[r-1]-s[l-1])<=m);
}
int find(int pos){
    int l=1,r=pos-1,mid,ans=pos;
    //int cnt=0;
    while(l<=r){
        //if(cnt>=10)break;
        mid=(l+r)>>1;
        //cout<<l<<" "<<r<<" "<<mid<<endl;
        if(check(mid,pos)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
        //cnt++;
    }
    return ans;
}*/
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
   
    if(n==1){
        cout<<1;
        return 0;
    }
    if(a[2]-a[1]>m){
        cout<<1;
        return 0;
    }
    ll ans=2,res,pos=1;

    for(int i=3;i<=n;i++){
        res=1;
        if(a[i]-a[i-1]>m)break;
 //     return (a[r]*(r-l)-(s[r-1]-s[l-1])<=m);
       
        /*pos=find(i);
        cout<<pos<<endl;
        res=i-pos+1;
        ans=max(ans,res);*/

        while(a[i]*(i-pos)-(s[i-1]-s[pos-1])>m)pos++;
        //cout<<"pos="<<pos<<" use=";
        //cout<<a[i]*(i-pos)-(s[i-1]-s[pos-1])<<" res="<<i-pos+1<<endl;
        //cout<<"****"<<a[i]*(i-pos)<<" "<<(s[i-1]-s[pos-1])<<endl;
        ans=max(ans,i-pos+1);
    }
    cout<<ans;
    return 0;
}