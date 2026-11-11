#include <bits/stdc++.h>
using namespace std;
long long m,mid,ans,ANS;
int n,idx,cnt,sum,ans1,mid1;
int a[200005];
char c[200005];
string s,s1,s2;
int main () {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>a[i]>>c[i];
        s+=c[i];
        m+=a[i];
    }
    mid=(m+1)/2;
    ans=m-mid;
    if(s.size()%2==0) mid1=s.size()/2-1;
    else mid1=s.size()/2;
    ans1=s.size()-1-mid1;
    ANS=ans-ans1;
    if(s.size()%2==1) {
        idx=(s.size()+1)/2;
        s1=s.substr(0,idx-1);
        s2=s.substr(idx);
        sum=s2.size();
        for(int i=0; i<s1.size(); i++) {
            sum--;
            if(s1[i]!=s2[sum]) cnt++;
        }
        if(cnt!=0) cout<<cnt+ANS;
        else cout<<0;
    }
    else {
        idx=s.size()/2;
        s1=s.substr(0,idx);
        s2=s.substr(idx);
        sum=s2.size();
        for(int i=0; i<s1.size(); i++) {
            sum--;
            if(s1[i]!=s2[sum]) cnt++;
        }
        if(cnt!=0) cout<<cnt+ANS;
        else cout<<0;
    }
    return 0;
}
