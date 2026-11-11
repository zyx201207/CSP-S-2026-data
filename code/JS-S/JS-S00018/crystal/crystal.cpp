#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=a[n],ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        int num=0;
        ll x=m,mina=0x3f3f3f3f,maxa=-1;
        bool f=0;
        for(int i=n;i>=1;i--){
            if(a[i]>mid){
                mina=a[i];
            }
            else if(a[i]<mid &&maxa==-1 &&mid-a[i]){
                maxa=a[i];
            }
            if(a[i]<=mid && mid-a[i]<=x){
                num++;
                x-=(mid-a[i]);
                if(i==1)f=1;
            }


        }
        if(mina-mid<=mid-maxa)f=1;
        if(num>ans){
            ans=num;
            if(f==1){
                l=mid+1;
            }
            else{
                r=mid-1;
            }

        }
        else{
            if(f==1)l=mid+1;
            else r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
/*freopen
quanju/jubu
return 0
()[]{}
endl->\n
int->ll
*/
