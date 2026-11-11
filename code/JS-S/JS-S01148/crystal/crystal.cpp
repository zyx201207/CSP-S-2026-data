#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],pre[N],ans;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for (int i=1;i<=n;i++) {//though the 'i' is called 'i', it's the 'j' in the explanations below 
        int l=1,r=i;
        while (l<r) {
            int mid=(l+r)>>1;//the 'mid' is the real 'i' in the explanations below
            if ((i-mid)*a[i]-pre[i-1]+pre[mid-1]<=m) l=mid+1;
            else r=mid;
        }
        ans=max(ans,l);
    }
    cout<<ans<<endl;
    return 0;
}
/*
First sort the A.
Easily to find that when we choose the crystals s to e (s<=e), we should pay sum(i=s,e)(Ae-Ai) price, which is ((e-s)*Ae-(sum(i=s,e-1)Ai)).
So we calculate the prefix of A to calculate sum(i=s,e-1)Ai in O(1), and then we use binary sort to search possible s for a certain e.
The smallest s is what we want for e-s+1 is the answer when the A ends with e.
The code's time is at O(nlogn), acceptted(perhaps).
*/
/*
I am ROBIN's DOG!!!
Miss ROBIN!!! I am your fans!!!
This is true music!
*/
//Honkai:Starail UID : 152884855
