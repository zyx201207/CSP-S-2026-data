#include <bits/stdc++.h>
using namespace std;
struct node{
    long long x;
    string s;
}a[200005];
int n;
long long r,mid,b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].x >> a[i].s;
        r+=a[i].x;
        b[i]=r;
    }
    mid=(r+1)/2;
    int h=lower_bound(b+1,b+1+n,mid)-b;
    long long ans=0;
    if(b[h]!=mid) a[h].x-=(b[h]-mid);
    int j=n;
    for(int i=1;i<=h;i++){
        if(a[i].x==0) continue;
        while(a[i].x>0){
            if(a[i].s==a[j].s){
                if(a[i].x>=a[j].x){
                    a[i].x-=a[j].x;
                    a[j].x=0;
                    j--;
                }
                else{
                    a[j].x-=a[i].x;
                    a[i].x=0;
                }
            }
            else{
                if(a[i].x>=a[j].x){
                    ans+=a[j].x;
                    a[i].x-=a[j].x;
                    a[j].x=0;
                    j--;
                }
                else{
                    ans+=a[i].x;
                    a[j].x-=a[i].x;
                    a[i].x=0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}