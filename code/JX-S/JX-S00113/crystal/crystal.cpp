#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,p,ans,a[N],mc=LLONG_MAX,mi,s[N];
bool fa=1,fb=1;
bool check(int x){ 
    int j=a[mi],l=mi,r=mi,mm=m,sum=1;
    while(r-l+1<x){
        if(l>1&&j-a[l-1]<=(r-l+1)*(a[r+1]-j)&&mm>=j-a[l-1]){
            mm-=j-a[l-1];
            l--;
        }else if(r<n&&mm>=(r-l+1)*(a[r+1]-j)){
            mm-=(r-l+1)*(a[r+1]-j);
            j=a[r+1];
            r++;
        }else return 0;
    }return 1;
    /*for(int i=mi-1;i>0;i--){
        while((mi-i+1)*(a[mi+1]-j)<j-a[i]&&mm>=(mi-i+1)*(a[mi+1]-j)){
            sum++;
            j=a[mi+1];
        }if(mm>=j-a[i]){
            mm-=j-a[i];
            sum++;
            if(sum>=x) return 1;
        }else return 0;
    }return 0;*/

}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) fa=0;
        p+=a[i];
        s[i]=s[i-1]+a[i];
    }for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]) fb=0;
    }p/=n;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(abs(a[i]-p)<=mc){
            mc=abs(a[i]-p);
            mi=i;
        }
    }//while(a[mi+1]*(mi+1)-s[mi+1]+s[0]<m) mi++;
    if(fa){
        int cnt=0;
        ans=1;
        while(m>=++cnt){
            m-=cnt;
            ans++;
            if(ans==n) break;
        }cout<<ans<<"\n";
        return 0;
    }if(fb){
        int cnt=0,c=a[2]-a[1];
        while(m>=cnt){
            m-=cnt;
            ans++;
            cnt+=c;
            if(ans==n) break;
        }cout<<ans<<"\n";
        return 0;
    }int l=1,r=n,mid=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }cout<<ans<<"\n"; 
    return 0;
}