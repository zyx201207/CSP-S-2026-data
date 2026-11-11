#include<bits/stdc++.h>
#define long long int
using namespace std;
int n;
struct Node {
    int s;
    char c;
}a[114514*2];
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    cin>>n;
    int len=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i].s>>a[i].c;
        len+=a[i].s;
    }
    int j=0;
    int ans=0;
    int n1=n;
    int mid=(len+1)/2;
    for(int i=1;i<=n;i++) {
       j+=a[i].s;
       if(j>mid) break;
       if(a[i].c!=a[n1].c) {
        if(a[i].s==a[n1].s) {
            ans+=a[i].s;
            n1--;
        }
        else if(a[i].s<a[n1].s) {
            ans+=a[i].s;
            a[n1].s-=a[i].s;
        }
        else {
            ans+=a[n1].s;
            a[i].s-=a[n1].s;
            n1--;
            i--;
        }
       }
       else {
        n1--;
       }
    }
    cout<<ans;
    return 0;
}
//password:Trick||Treat!
