#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
string s;
long long ans=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1]){
            a[i-1]+=a[i];
            i--;
            n--;
        }
    }
    int l=1;
    int r=n;
    long long t;
    while(l<r){
        t=min(a[l],a[r]);
        a[l]-=t;
        a[r]-=t;
        if(c[l]!=c[r]){
            ans+=t;
        }
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout<<ans<<"\n";
    return 0;
}


