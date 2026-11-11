#include<bits/stdc++.h>
using namespace std;
int n,s;
long long b=0;
bool f[200005];
struct node{
    long long l,r;
    char z;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>a[i].z;
        a[i].l=b+1;
        a[i].r=b+s;
        b+=s;
    }
    long long mid=b/2;
    long long ans=0;
    int j=n-1;
    for(int i=0;i<n&&j>=i;i++){
        if(mid>=a[i].l&&mid<=a[i].r){
            long long x=mid+1+b%2,y=b+1-a[i].l;
            while(x<=a[j].r&&j>=i){
                if(a[j].z==a[i].z){
                    ans+=min(y,a[j].r)-max(x,a[j].l)+1;
                }
                if(a[j].l<x){
                    break;
                }else{
                    j--;
                }
            }
            break;
        }else{
            long long x=b+1-a[i].r,y=b+1-a[i].l;
            while(x<=a[j].r&&j>=i){
                if(a[j].z==a[i].z){
                    ans+=min(y,a[j].r)-max(x,a[j].l)+1;
                }
                if(a[j].l<x){
                    break;
                }else{
                    j--;
                }
            }
        }
    }
    cout<<b/2-ans;
    return 0;
}
