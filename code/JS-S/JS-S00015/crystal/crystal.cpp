#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500001],b[500001],l,r,sum,t;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>0;i--){
        b[i]=a[i]-a[i-1];
    }
    while(r<n){
        if(t+(r-l+1)*b[r+1]<=m){
            t+=(r+1-l)*b[r+1];
            r++;
        }
        else{
            t-=a[r]-a[l];
            l++;
        }
        sum=max(sum,r-l+1);
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
