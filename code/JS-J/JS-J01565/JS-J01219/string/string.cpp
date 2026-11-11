#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+10;
ll n,a[MAXN],l[MAXN],r[MAXN],L,ans;
char c[MAXN];
ll find(ll x){
    ll LL=1,RR=n,ans=-1;
    while(LL<=RR){
        ll mid=LL+RR>>1;
        if(r[mid]<x) LL=mid+1;
        else if(l[mid]>x) RR=mid-1;
        else return mid;
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        l[i]=r[i-1]+1;r[i]=l[i]+a[i]-1;
    }
    ll mid1=(L+1)/2,mid2=(L+2)/2,lst=-1;
    ans+=(c[find(mid1)]!=c[find(mid2)]);mid1--,mid2++;
    for(;mid1>=1&&mid2<=L;){
        //cout<<mid1<<" "<<mid2<<" "<<" 101002\n";
        ll pos1=find(mid1),pos2=find(mid2);
        if(mid1+mid2-l[pos1]>r[pos2]){
            ans+=(c[pos1]!=c[pos2])*(r[pos2]-mid2+1);
            mid1=mid1+mid2-r[pos2]-1;mid2=r[pos2]+1;
        }
        else{
            ans+=(c[pos1]!=c[pos2])*(mid1-l[pos1]+1);
            mid2=mid1+mid2-l[pos1]+1;mid1=l[pos1]-1;
        }
        //cout<<pos1<<" "<<pos2<<"\n";
        //cout<<ans<<"\n";
    } 
    cout<<ans<<"\n";
    return 0;
}