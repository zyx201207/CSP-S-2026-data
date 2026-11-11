#include<bits/stdc++.h>
using namespace std;
int n,l,q,a[200010],ans;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>l;
    for(int i=1;i<=l;i++){
        cin>>a[i]>>c[i];
        n+=a[i];
    }
    n/=2;
    int ldk=1,lsum=0,rdk=l;
    while(1){
        if(lsum>=n) break;
        if(c[ldk]!=c[rdk]){
            if(a[ldk]<a[rdk]){
                ans+=a[ldk];
                lsum+=a[ldk];
                a[rdk]-=a[ldk];
                ldk++;
            }
            else if(a[ldk]>a[rdk]){
                ans+=a[rdk];
                lsum+=a[rdk];
                a[ldk]-=a[rdk];
                rdk--;
            }
            else if(a[ldk]==a[rdk]){
                ans+=a[rdk];
                lsum+=a[ldk];
                a[ldk]=a[rdk]=0;
                rdk--;
                ldk++;
            }
        }
        else{
            if(a[ldk]<a[rdk]){
                lsum+=a[ldk];
                a[rdk]-=a[ldk];
                ldk++;
            }
            else if(a[ldk]>a[rdk]){
                lsum+=a[rdk];
                a[ldk]-=a[rdk];
                rdk--;
            }
            else if(a[ldk]==a[rdk]){
                lsum+=a[ldk];
                a[ldk]=a[rdk]=0;
                rdk--;
                ldk++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
