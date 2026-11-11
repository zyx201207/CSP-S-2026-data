#include<bits/stdc++.h>
using namespace std;
char c[10000000],c1[1000000],c2[1000000],cc;
long long a[1000000],a1[1000000],a2[1000000],ans;
long long n,t,mid,r,l,u,m;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>cc;
        mid+=n;
        c[i]=cc;
        a[i]=n;
        m+=n;
    }mid=mid/2+mid%2;
    for(int i=1;i<=t;i++){
        if(r<= mid&&r+a[i]>=mid)l=i;
        if(r<=mid&&r+a[i]>=mid){
            l=i;
            u=1;
            a1[i]=mid-r-m%2;
            a2[i-l+u]=r+a[i]-mid;
            c1[i]=c[i];
            c2[i-l+u]=c[i];
        }else if(r<mid){
            a1[i]=a[i];
            c1[i]=c[i];
        }else if(r>mid){
            a2[i-l+1]=a[i];
            c2[i-l+1]=c[i];
        }r+=a[i];
    }
    //for(int i=1;i<=l;i++){
     //   cout<<a1[i]<<" "<<c1[i]<<endl;
    //}cout<<endl<<mid<<endl;
    //for(int i=1;i<=t-l+1;i++){
     //   cout<<a2[i]<<" "<<c2[i]<<endl;
    //}
    int k1=1,k2=1;
    for(int i;;){
        if(c1[k1]!=c2[k2]){
            ans+=min(a1[k1],a2[k2]);
        }
        a1[k1]-=min(a1[k1],a2[k2]);
        a2[k2]-=min(a1[k1],a2[k2]);
        if(a1[k1]==0)k1++;
        if(a2[k2]==0)k2++;
        if(k1>l||k2>t-l+1)break;
    }cout<<ans;
    return 0;
}

