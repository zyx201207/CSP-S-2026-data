#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll sum,n,a[N];
char c[N],last;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    ll l=1,r=n;
    while(l<=r){
        if(a[l]==a[r]&&c[l]==c[r]){
            l++;
            r--;
        }else if(a[l]!=a[r]&&c[l]==c[r]){
            if(a[l]>a[r]){
                a[l]-=a[r--];
            }else{
                a[r]-=a[l++];
            }
        }else if(a[l]==a[r]&&c[l]!=c[r]){
            sum+=a[l];
            l++;
            r--;
        }else{
            if(a[l]>a[r]){
                sum+=a[r];
                a[l]-=a[r--];
            }else{
                sum+=a[l];
                a[r]-=a[l++];
            }
        }
    }
    cout<<sum;
    return 0;
}
