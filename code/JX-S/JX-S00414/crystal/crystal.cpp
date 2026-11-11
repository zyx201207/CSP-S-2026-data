#include<bits/stdc++.h>
using namespace std;
signed long long n,m,a[50005],b[50005];
int work1(){
    int l=0,r=n,mid=(l+r)/2;
    while(l<r){
        mid=(l+r)/2;
        int c=(mid-1)*mid;
        if(c<m)r=mid;
        else if(c==m)return mid;
        else l=mid;
    }
    return mid;
}
int work2(int ch){
    int l=1,r=n,mid=(l+r)/2;
    while(l<=r){
        mid=(l+r)/2;
        int c=a[mid]*(mid-1)-(a[mid]-ch+a[1])*(mid-1)/2;
        if(c>m)r=mid-1;
        else if(c==m)return mid;
        else l=mid+1;
    }
    return mid;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool flag1=1,flag2=1;
    for(int i=1;i<=n;i++){
        if(i==1){
            cin>>a[i];
            b[i]=a[i];
            if(a[i]!=i)flag1=0;
            continue;
        }
        cin>>a[i];
        b[i]=b[i-1]+a[i];
        if(a[i]!=i)flag1=0;
        if(a[i]-a[i-1]!=a[2]-a[1])flag2=0;
    }
    if(flag1){
        cout<<work1();
        return 0;
    }
    else if(flag2){
        cout<<work2(a[2]-a[1]);
        return 0;
    }
    else{
        int r=n,l=1;
        sort(a+1,a+1+n);
        while(m<a[r-l+1]*(r-l)-(b[r-1]-b[l]+1)){
            if(a[l+1]-a[l]>a[r]-a[r-1])l++;
            else r--;
        }
        cout<<r-l+1;

    }
    return 0;
}
