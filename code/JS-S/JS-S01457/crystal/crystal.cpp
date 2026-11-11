#include<bits/stdc++.h>
using namespace std;
int sor[500005];
void so(int a[],int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    so(a,l,mid);
    so(a,mid+1,r);
    int lp=l;
    int rp=mid+1;
    int p=0;
    while(lp<=mid&&rp<=r){
        if(a[lp]<=a[rp]){
            sor[p]=a[lp];
            p++;
            lp++;
        }else{
            sor[p]=a[rp];
            p++;
            rp++;
        }
    }
    if(lp>mid){
        while(rp<=r)sor[p++]=a[rp++];
    }else{
        while(lp<=mid)sor[p++]=a[lp++];
    }
    for(int k=0;k<=r-l;k++){
        a[l+k]=sor[k];
    }
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    int a[n+1];
    int b[n+1];
    int l[n+1];
    for(int k=0;k<n;k++){
        cin>>a[k];
        b[k]=0;
    }
    so(a,0,n-1);
    for(int k=0;k<n-1;k++){
        b[k]=a[k+1]-a[k];
    }
    int ans=1,t1=1,t2=2,t3=n-1,p=0;
    while(1){
        for(int k=0;k<n-t2;k++){
            long long co=0;
            for(int k1=1;k1<=t2;k1++){
                co+=b[k+k1-1]*k1;
            }
            if(co<=m){
                p=1;
                break;
            }
        }
        int midt;
        if(p==1){
            if(t2==t3){
                ans=t2;
                break;
            }
            if((t2<<1)<=t3){
                t1=t2;
                t2=t2<<1;
            }else{
                if(t2+1==t3){
                    t1=t2;
                    t2=t3;
                }else{
                    midt=(t2+t3)>>1;
                    t1=t2;
                    t2=midt;
                }
            }
        }else{
            midt=(t1+t2)>>1;
            if(midt==t1){
                ans=t1;
                break;
            }else{
                t3=t2;
                t2=midt;
            }
        }
        p=0;
    }
    cout<<ans+1<<endl;
    return 0;
}
