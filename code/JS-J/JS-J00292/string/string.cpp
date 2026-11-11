#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],c;
ll zh,zhb;
char cs[N];

int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>cs[i];
        zh+=a[i];

    }
    zhb=zh/2;
    int l=1,r=n,bt=zhb;
    while(bt>0){
        if(l!=r){

            if(cs[l]!=cs[r]){
                c+=min(a[l],a[r]);
            }
            if(a[l]<a[r]){
                bt-=a[l];
                a[r]-=a[l];
                a[l]==0;
                l++;
            }
            else if(a[r]<a[l]){
                bt-=a[r];
                a[l]-=a[r];
                a[r]==0;
                r--;
            }
            else{
                bt-=a[l];
                a[l]=0;
                a[r]=0;
                l++;
                r--;
            }
        }
        else break;

    }
    cout<<c;
    return 0;
}
