#include<bits/stdc++.h>
using namespace std;
int n,num;
long long ans=0,a[200005];
char c[200005];
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==' '){
            cin>>c[i];
        }
    }
    int l=0,r=n-1;
    while(l<=r){
        int to_s=min(a[l],a[r]);
        if(c[l]!=c[r])  ans+=to_s;
        if(a[l]<a[r]){
            a[r]-=to_s;
            l++;
        }
        else if(a[l]>a[r]){
            a[l]-=to_s;
            r--;
        }
        else{
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
