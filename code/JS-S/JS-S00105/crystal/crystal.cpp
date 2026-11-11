#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll chaa[500005];
ll ans[500005];
bool flagg=true,flag=false;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll T=a[2]-a[1];
    for(int i=1;i<=n;i++){
        if(i>=2 && a[i]-a[i-1]!=T){
            flagg=false;
        }
    }
    if(flagg==true && T==1){
        flag=true;
    }
    if(flag==true){
        ll cnt=0;
        for(ll i=1;;i+=1){
            m-=i;
            if(m<0){
                cnt=i-1;
                break;
            }
        }
        cout<<cnt+1<<endl;;
        return 0;
    }//A

    if(flagg==true){
        ll cnt=0;
        for(ll i=T;;i+=T){
            m-=i;
            if(m<0){
                cnt=i/T-1;
                break;
            }
        }
        cout<<cnt+1<<endl;;
        return 0;
    }//B
    chaa[1]=0;
    for(int i=2;i<=n;i++){
        chaa[i]=a[i]-a[1];
    }
    map<ll,ll>mp;
    for(int i=1;i<=n;i++){
        mp[a[i]]++;
//            maxn=max(maxn,mp[a[i]]);
    }
    if(n<=5000 && m<=1000){
        ll maxn=LLONG_MIN;
        memset(ans,0,sizeof(ans));
        for(int i=2;i<=n;i++){
            ll mmm=m;
            if(mp[a[i]]!=0){
                i+=mp[a[i]]-1;
            }
            for(int j=i-1;j>=1;j--){
                mmm=mmm-(chaa[i]-chaa[j]);
                if(mmm<0){
                    break;
                }
                ans[i]++;
            }
        }
        bool minn=false;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,ans[i]);
            if(ans[i]!=0 && minn==false){
                minn=true;
            }
        }
 //       for(int i=1;i<=n;i++){
  //          cout<<ans[i]<<" ";
 //       }
 //       cout<<endl;
        if(minn==false){
            cout<<"1"<<endl;
        }
        else{
            cout<<maxn+1<<endl;
        }
        return 0;
    }//1~5
    else{
        memset(ans,0,sizeof(ans));
        ll maxn=LLONG_MIN;
        for(int i=2;i<=n;i++){
            ll mmm=m;
            if(mp[a[i]]!=0){
                i+=mp[a[i]]-1;
            }
            for(int j=i-1;j>=1;j--){
                mmm=mmm-(chaa[i]-chaa[j]);
                if(mmm<0){
                    break;
                }
                ans[i]++;
            }
        }
        bool minn=false;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,ans[i]);
            if(ans[i]!=0 && minn==false){
                minn=true;
            }
        }
 //       for(int i=1;i<=n;i++){
  //          cout<<ans[i]<<" ";
 //       }
 //       cout<<endl;
        if(minn==false){
            cout<<"1"<<endl;
        }
        else{
            cout<<maxn+1<<endl;
        }
        return 0;
    }//wu
    return 0;
}//I L X Q Y
