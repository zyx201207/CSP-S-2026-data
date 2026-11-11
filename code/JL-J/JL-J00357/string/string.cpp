#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
int f(int l,int r){
    int mid=(l+r)>>1;
    if(l==r)return mid;
    if(){l=mid;return(l,r);}
    else{r=mid;return(l,r);}
}
*/
struct f{int x;char y;};
f a[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        char c;
        cin>>m>>c;
        a[i]={m,c};
    }
    ll cnt=0;
    int l=1,r=n;
    while(l!=r){
        if(a[l].x==0){
            l++;
            continue;
        }
        if(a[r].x==0){
            r--;
            continue;
        }
        if(a[l].y==a[r].y){
            if(a[l].x>a[r].x){
                a[l].x-=a[r].x;
                a[r].x=0;
            }
            else{
                a[r].x-=a[l].x;
                a[l].x=0;
            }
            continue;
        }
        else{
            if(a[l].x>a[r].x){
                a[l].x-=a[r].x;
                cnt+=a[r].x;
                a[r].x=0;
            }
            else{
                a[r].x-=a[l].x;
                cnt+=a[l].x;
                a[l].x=0;
            }
        }
    }
    cout<<cnt;
    return 0;
}
