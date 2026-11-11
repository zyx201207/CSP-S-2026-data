#include <iostream>
#include <cstdio>
using namespace std;
const int N=2e5+5;
int n;
int x[N];
char c[N];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            if(x[l]<x[r]){
                ans+=x[l];
                x[r]-=x[l];
                x[l]=0;
            }else{
                ans+=x[r];
                x[l]-=x[r];
                x[r]=0;
            }
        }else{
            if(x[l]<x[r]){
                x[r]-=x[l];
                x[l]=0;
            }else{
                x[l]-=x[r];
                x[r]=0;
            }
        }
        if(x[l]==0)l++;
        if(x[r]==0)r--;
    }
    cout<<ans;
    return 0;
}