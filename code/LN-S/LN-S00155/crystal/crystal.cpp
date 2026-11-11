#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++) s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
    int l=1;
    a[0]=a[1];
    int sum=INT_MIN;
    /*for(int i=1;i<=n;i++){
            cout<<s[i]<<" ";
        for(int j=1;j<=i;j++) cout<<s[i]-s[j-1]-(j-1)*(a[i]-a[j-1])<<" ";cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        while((s[i]-s[l-1]-(l-1)*(a[i]-a[l-1]))>m) l++;
        sum=max(sum,i-l+1);
        //cout<<l<<" ";
    }cout<<sum;
    return 0;
}
