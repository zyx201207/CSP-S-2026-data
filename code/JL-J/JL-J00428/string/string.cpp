#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int a[N];
int n;
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    int ans=0;
    for(;i<j;){
        if(c[i]!=c[j]){
            ans+=min(a[i],a[j]);
        }
        if(a[i]>a[j]){
            a[i]-=a[j];
            j--;
        }
        else if(a[i]<a[j]){
            a[j]-=a[i];
            i++;
        }
        else{
            a[i]=0;
            a[j]=0;
            i++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}
