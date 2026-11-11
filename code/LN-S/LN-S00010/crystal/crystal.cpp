#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+3;
long long m;
long long a[N],b[N];
int n,ans;
int main(){
    freopen("crystal4.in","r",stdin);
    freopen("crystal4.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    /*
    for(int i = 1;i<n;i++){
        b[i] = a[i]-a[1];
    }
    for(int i = n;i>=1;i--){
        int limit = m,k = i,t = 0,need = 0;
        while(limit>=need && k>=1){
            need = need*2+(a[k]-a[i]);
            t++;
            k--;
        }
        ans = max(ans,t);

        int l = 1,r = i;
        while(l<r){
            int mid = (l+r)/2;
            if(a[mid]<ll){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        ans = max(ans,i-l);
    }*/
    for(int i = n;i>=1;i--){
        int need = 0,t = 0,k = i;
        for(int j = i;j>=1;j--){
            need+=a[i]-a[j];
            if(need<=m) t++;
            else{
                break;
            }
        }
        ans = max(ans,t);
    }

    cout<<ans;
}
