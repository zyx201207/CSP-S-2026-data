#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
    int x;
    char c;
}a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int len=0;
    for(int i=1;i<=n;i++){
        cin >> a[i].x >> a[i].c;
        len+=a[i].x;
    }
    int l=1,r=len;
    int ll=1,rr=n;
    int ans=0;
    if(len%2==0){
        while(l<=len/2&&len/2<r&&ll<=rr){
            if(a[ll].x<a[rr].x){
                if(a[ll].c!=a[rr].c){
                    ans+=a[ll].x;
                }
                l+=a[ll].x;
                a[rr].x-=a[ll].x;
                ll++;
            }else{
                if(a[ll].c!=a[rr].c){
                    ans+=a[rr].x;
                }
                r-=a[rr].x;
                a[ll].x-=a[rr].x;
                rr--;
            }
        }
        cout << ans;
    }else{
        while(l<=len/2&&len/2+1<r&&ll<=rr){
            if(a[ll].x<a[rr].x){
                if(a[ll].c!=a[rr].c){
                    ans+=a[ll].x;
                }
                l+=a[ll].x;
                a[rr].x-=a[ll].x;
                ll++;
            }else{
                if(a[ll].c!=a[rr].c){
                    ans+=a[rr].x;
                }
                r-=a[rr].x;
                a[ll].x-=a[rr].x;
                rr--;
            }
        }
        cout << ans;
    }
    return 0;
}
