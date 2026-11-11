#include <iostream>
using namespace std;
int n;
long long a[200200],ans;
char c[200200];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r){
        if (c[l]!=c[r]){
            if (a[l]>a[r]){
                ans+=a[r],a[l]-=a[r],r--;
            }
            else if (a[l]<a[r]){
                ans+=a[l],a[r]-=a[l],l++;
            }
            else{
                ans+=a[l],l++,r--;
            }
        }
        else{
            if (a[l]>a[r]){
                a[l]-=a[r],r--;
            }
            else if (a[l]<a[r]){
                a[r]-=a[l],l++;
            }
            else{
                l++,r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
