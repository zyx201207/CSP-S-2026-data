#include <bits/stdc++.h>
using namespace std;
long long n,ans,sum,l=1,r;
long a[207891];
char b[206767];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }long long k=sum/2;
    if(sum%2==1){
        k++;
    }while(k<sum||l<=r){
        if(l==r){
            break;
        }if(b[l]==b[r]){
            if(a[l]==a[r]){
                sum-=a[l];
                l++;
                r--;
            }else if(a[l]>a[r]){
                sum-=a[r];
                a[l]-=a[r];
                r--;
            }else{
                sum-=a[l];
                a[r]-=a[l];
                l++;
            }
        }else{
            if(a[l]==a[r]){
                if(sum-a[r]<k){
                    ans+=sum-k;
                }else{
                    ans+=a[r];
                }
                sum-=a[l];
                l++;
                r--;
            }else if(a[l]>a[r]){
                if(sum-a[r]<k){
                    ans+=sum-k;
                }else{
                    ans+=a[r];
                }sum-=a[r];
                a[l]-=a[r];
                r--;
            }else{
                if(sum-a[l]<k){
                    ans+=sum-k;
                }else{
                    ans+=a[l];
                }sum-=a[l];
                a[r]-=a[l];
                l++;
            }
        }
    }cout<<ans;
    return 0;
}
