#include <bits/stdc++.h>
using namespace std;
long long sum,ans,mid;
int a[200005],n;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    long long arrleft=1,arrright=n,nownum=0,left,right;
    left=a[arrleft];
    right=a[arrright];
    while(nownum<sum/2){
        if(c[arrleft]!=c[arrright]){
            if(left>right){
                ans+=right;
                left-=right;
                arrright--;
                nownum+=right;
                right=a[arrright];
            }else if(left==right){
                ans+=right;
                arrleft++;
                arrright--;
                nownum+=right;
                left=a[arrleft];
                right=a[arrright];
            }else{
                ans+=left;
                right-=left;
                arrleft++;
                nownum+=left;
                left=a[arrleft];
            }
        }else{
            if(left>right){
                left-=right;
                arrright--;
                nownum+=right;
                right=a[arrright];
            }else if(left==right){
                arrleft++;
                arrright--;
                nownum+=right;
                left=a[arrleft];
                right=a[arrright];
            }else{
                right-=left;
                arrleft++;
                nownum+=left;
                left=a[arrleft];
            }
        }
    }
    cout<<ans;
    return 0;
}
