#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int len=0;
    vector<int> a(n+5);
    vector<char> c(n+5);
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    len/=2;
    int s1=0;
    vector<int> a1;
    vector<char> c1;
    for (int i=1;i<=n;i++) {
        a1.push_back(a[i]);
        c1.push_back(c[i]);
        if (s1+a[i]>len) {
            a1.back()=len-s1;
            break;
        }
        if (s1+a[i]==len) {
            break;
        }
        s1+=a[i];
    }
    int l1=a1.size();
    for (int i=1;i<l1;i++) {
        a1[i]+=a1[i-1];
    }
    int s2=0;
    vector<int> a2;
    vector<char> c2;
    for (int i=n;i>=1;i--) {
        a2.push_back(a[i]);
        c2.push_back(c[i]);
        if (s2+a[i]>len) {
            a2.back()=len-s2;
            break;
        }
        if (s2+a[i]==len) {
            break;
        }
        s2+=a[i];
    }
    int l2=a2.size();
    for (int i=1;i<l2;i++) {
        a2[i]+=a2[i-1];
    }
    int ans=0;
    int now=0,i=0,j=0;
    while (now<len) {
        if (a1[i]==a2[j]) {
            if (c1[i]!=c2[j]) {
                ans+=a1[i]-now;
            }
            now=a1[i];
            i++;j++;
        } else if (a1[i]>a2[j]) {
            if (c1[i]!=c2[j]) {
                ans+=a2[j]-now;
            }
            now=a2[j];
            j++;
        } else {
            if (c1[i]!=c2[j]) {
                ans+=a1[i]-now;
            }
            now=a1[i];
            i++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
