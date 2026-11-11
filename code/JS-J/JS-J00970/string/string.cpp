#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2e5+10;
int n;
long long a[N];
char c[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    long long ans=0;
    while(i<j){
        int k=min(a[i],a[j]);
        if(c[i]!=c[j])ans+=k;
        a[i]-=k;
        a[j]-=k;
        if(a[i]==0)i++;
        if(a[j]==0)j--;
    }
    cout<<ans;
    return 0;
}
