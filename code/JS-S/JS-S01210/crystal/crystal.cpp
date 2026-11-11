#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int maxn=1;
    for(int i=n-1;i>=0;i--){
        long long s=0;
        for(int j=0;;j++){
            s+=a[i]-a[i-j];
            if(s>m){
                maxn=max(maxn,j);
                break;
            }
            if(i==j){
                maxn=max(maxn,j+1);
                break;
            }
        }
    }
    cout<<maxn;
    return 0;
}
