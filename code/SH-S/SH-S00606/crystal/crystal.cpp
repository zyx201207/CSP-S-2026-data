#include <bits/stdc++.h>
using namespace std;
long long m,a[500010],cnt=0;
int n,ans=0;
// int half_find(int l,int r,int aim){
//     int mid=(l+r)/2;
//     long long cn=0;
//     for(int i=mid;i<aim;i++){
//         cn+=a[aim]-a[i];
//         if(cn>m) break;
//     }
//     if(mid==l){
//         if(cn>m){
//             return mid+1;
//         }
//         if(mid==1) return mid;
//         if(cn<m&&cn+a[aim]-a[mid-1]<m) return mid-1;
//     }
//     if(cn>m) return half_find(mid,r,aim);
//     else if(cn==m) return mid;
//     else if(cn<m&&cn+a[aim]-a[mid-1]>m) return mid;
//     else if(cn<m&&cn+a[aim]-a[mid-1]<m) return half_find(l,mid,aim);
//     else if(cn<m&&cn+a[aim]-a[mid-1]==m) return mid-1;
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long d=a[2]-a[1];
    bool ab=true;
    for(int i=2;i<n;i++){
        if(a[i+1]-a[i]!=d){
            ab=false;
            break;
        }
    }
    if(ab==true){
        for(int i=n;i>=1;i--){
            if(i*(1+i)/2*d<=m){
                cout<<i+1;
                return 0;
            }
        }
    }
    for(int i=n;i>1;i--){
        cnt=0;
        int j=i-1;
        for(;j>1;j--){
            if(cnt+a[i]-a[j]==m) break;
            if(cnt+a[i]-a[j]>m){
                j++;
                break;
            }
            cnt=cnt+a[i]-a[j];
        }
        ans=max(ans,i-j+1); 
        // ans=max(ans,i-half_find(1,i-1,i)+1);
    }
    cout<<ans;
    return 0;
}
