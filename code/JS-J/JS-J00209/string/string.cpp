#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,c;
int a[200005],b[200005],ac[200005],bc[200005];
char ch;
string s="",s1;
ll len;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t>>ch;
        c=ch-'a'+1;
        len+=t;
        a[i]=b[n-i+1]=t;
        ac[i]=bc[n-i+1]=c;
        for(int j=1;j<=t;j++){
            s+=ch;
        }
    }
    s1=s;
    reverse(s.begin(),s.end());
    ll ans=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s1[i])ans++;
    }
    /*ll mid=len/2+len%2;
    ll l=1,r=1,l1=1,r1=1,ans=0;
    while(l<mid||r<mid){
        if(ac[l]!=bc[r]){
            ans+=min(a[l],b[r]);
        }

        l1+=min(a[l],b[r]);
        r1+=min(a[l],b[r]);
        if(l1>=a[l]){
            l1%=a[l]+1;
            l++;
        }
        if(r1>=b[r]){
            r1%=b[r]+1;
            r++;
        }

    }*/
    cout<<ans;
    return 0;
}
