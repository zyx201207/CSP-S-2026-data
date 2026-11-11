#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,l[200010],r[200010],l1,r1,ans;
char c[200010];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    ans=0;
    l1=1;
    r1=n;
    while(l1<=r1){
        if(c[l1]!=c[r1]){
            if(a[l1]<=a[r1]){
                ans+=a[l1];
                a[r1]-=a[l1];
                l1++;
            }else{
                ans+=a[r1];
                a[l1]-=a[r1];
                r1--;
            }
        }else{
            if(a[l1]<=a[r1]){
                a[r1]-=a[l1];
                l1++;
            }else{
                a[l1]-=a[r1];
                r1--;
            }
        }
    }
    cout<<ans;
    return 0;
}
