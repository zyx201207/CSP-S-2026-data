#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
int n,t[150],a[N];
ll ans=0,sum=0;
char c[N];
string s1,s2;
int main(){
    IOS;
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int aa;
        char cc;
        cin>>aa>>cc;
        ans+=aa;
        a[i]=aa;
        c[i]=cc;
    }
    cout<<ans<<endl;
    int j=1;
    for(int i=1;i<=(ans+2-1)/2;i++){
        if(a[j]<=0)j++;
        s1+=c[j];
        a[j]--;
    }
    for(int i=(ans+2-1)/2;i<=ans;i++){
        if(a[j]<=0)j++;
        s2+=c[j];
        a[j]--;
    }
    cout<<s1<<" "<<s2<<endl;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i])sum++;
    }
    cout<<sum;
    return 0;
}
