#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+9;
int a[maxn];
char c[maxn];
int n;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    int L=0,R=0;
    int ans=0;
    while(l<r){
        //cout<<l<<' '<<r<<"*\n";
        int s=L,t=R;
        if(s==0&&t==0){
            s=a[l];t=a[r];
        }
        else if(s==0&&t!=0){
            s=a[l];
        }
        else if(s!=0&&t==0){
            t=a[r];
        }


        if(1){
            if(s==t){
                if(c[l]!=c[r]) ans+=s;
                l++;r--;
                L=0,R=0;
            }
            if(s>t){
                if(c[l]!=c[r]) ans+=t;
                L=s-t;R=0;
                r--;
            }
            if(s<t){
                if(c[l]!=c[r]) ans+=s;
                R=t-s;L=0;
                l++;
            }
        }

    }
    cout<<ans;
    return 0;
}
/*
3
2 a
2 b
1 c
*/
/*
4
3 a
2 b
1 c
1 d
*/

