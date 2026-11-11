#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[200010];
char c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int li=1,ri=n,l=0,r=0;
    while(li<ri){
        int x=a[li]-l,y=a[ri]-r;
        if(x<y){
            l=0;
            if(c[li]!=c[ri]) ans+=x;
            li++;
            r+=x;
        }
        else if(x>y){
            r=0;
            if(c[li]!=c[ri]) ans+=y;
            ri--;
            l+=y;
        }
        else{
            l=r=0;
            if(c[li]!=c[ri]) ans+=x;
            li++;ri--;
        }
    }
    cout<<ans;
    return 0;
}
