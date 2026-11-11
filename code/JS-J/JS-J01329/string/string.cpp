#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],l,r;
string s;
char c[N];
long long iq(){
    long long ans=0;
    while(l<r){
        int m=min(a[l],a[r]);
        if(c[l]!=c[r])ans+=m;
        a[l]-=m;
        a[r]-=m;
        if(a[l]==0)l++;
        if(a[r]==0)r--;
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    l=0,r=n-1;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    cout<<iq();
    return 0;
}
