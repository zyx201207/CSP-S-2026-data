#include<bits/stdc++.h>
using namespace std;
string s[200005];
long long a[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>s[i];
    int l=1,r=n;
    while(l<r){
        if(s[l]!=s[r])
            ans+=min(a[l],a[r]);
        if(a[l]<a[r])
            a[r]-=a[l],l++;
        else if(a[l]>a[r])
            a[l]-=a[r],r--;
        else
            l++,r--;
    }
    cout<<ans;
    return 0;
}
