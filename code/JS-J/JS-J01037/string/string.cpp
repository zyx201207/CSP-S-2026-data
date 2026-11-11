#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    long long a[n+5];
    char c[n+5];
    for (int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n;
    long long i=a[l],j=a[r],ans=0;
    while (l<r){
        if (c[l]==c[r]){
            if (i==j){
                l++;
                r--;
                i=a[l];
                j=a[r];
            }
            else if (i<j){
                j-=i;
                l++;
                i=a[l];
            }
            else {
                i-=j;
                r--;
                j=a[r];
            }
        }
        else {
            if (i==j){
                ans+=i;
                l++;
                r--;
                i=a[l];
                j=a[r];

            }
            else if (i<=j){
                j-=i;
                ans+=i;
                l++;
                i=a[l];

            }
            else {
                i-=j;
                ans+=j;
                r--;
                j=a[r];
            }
        }

    }
    cout<<ans;
    return 0;
}
