#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
int n;
int x[N];
string c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>c[i];
    }
    int cnt=0,l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            if(x[r]>x[l]){
                cnt+=x[l];
                x[r]-=x[l];
                l++;
            }else if(x[l]>x[r]){
                cnt+=x[r];
                x[l]-=x[r];
                r--;
            }else {
                cnt+=x[l];
                l++;
                r--;
            }
        }else {
            if(x[l]>x[r]){
                x[l]-=x[r];
                r--;
            }
            else if(x[l]<x[r]){
                x[r]-=x[l];
                l++;
            }
            else {
                r--;
                l++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
