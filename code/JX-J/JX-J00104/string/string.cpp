#include <iostream>
using namespace std;
long long n,cnt[200005],ans;
char a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cnt[i]>>a[i];
    }
    int l=1,r=n;
    while(l<r){
        if(cnt[l]<cnt[r]){
            if(a[l]!=a[r]) ans+=cnt[l];
            cnt[r]-=cnt[l];
            cnt[l]=0;
            l++;
        }else if(cnt[l]>cnt[r]){
            if(a[l]!=a[r]) ans+=cnt[r];
            cnt[l]-=cnt[r];
            cnt[r]=0;
            r--;
        }else{
            if(a[l]!=a[r]) ans+=cnt[l];
            cnt[l]=cnt[r]=0;
            l++;r--;
        }
    }
    cout<<ans;
    return 0;
}
