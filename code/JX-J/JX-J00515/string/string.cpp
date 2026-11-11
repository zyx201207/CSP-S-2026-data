#include<bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int l=0,r=n-1;
    long long cnt=0;
    while(l<r){
        if(b[l]!=b[r]){
            if(a[l]<a[r]){
                cnt+=a[l];
                a[r]-=a[l];
                a[l]=0;
            }
            else{
                cnt+=a[r];
                a[l]-=a[r];
                a[r]=0;
            }
        }
        else{
            if(a[l]<a[r]){
                a[r]-=a[l];
                a[l]=0;
            }
            else{
                a[l]-=a[r];
                a[r]=0;
            }
        }
        if(a[l]==0){
            l++;
        }
        if(a[r]==0){
            r--;
        }
    }
    cout<<cnt;
    return 0;
}
