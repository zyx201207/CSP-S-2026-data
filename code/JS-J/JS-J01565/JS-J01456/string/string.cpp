#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,ans,a[N];
char s[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>s[i];
    }
    int i=0,j=n-1;
    while(i<j){
        if(s[i]!=s[j]){
            ans+=min(a[i],a[j]);
        }
        if(a[i]>a[j]){
            a[i]-=a[j];
            j--;
        }else if(a[i]==a[j]){
            i++;j--;
        }else{
            a[j]-=a[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
