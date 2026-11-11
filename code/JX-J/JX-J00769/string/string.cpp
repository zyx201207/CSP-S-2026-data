#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define int long long
int n,tot=0,ans=0;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    vector<int> a(n+5),f(n+5);
    vector<char> c(n+5),fc(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]!=c[i-1]){
            tot++;
            f[tot]+=a[i];
            fc[tot]=c[i];
        }
        else{
            f[tot]+=a[i];
        }
    }
    if(tot==1){
        cout<<0;
    }
    else{
        int l=1,r=tot;
        while(l<=r){
            if(fc[l]==fc[r]){
                if(f[l]>f[r]){
                    f[l]-=f[r];
                    r--;
                }
                else if(f[l]<f[r]){
                    f[r]-=f[l];
                    l++;
                }
                else{
                    f[l]=f[r]=0;
                    l++;
                    r--;
                }
            }
            else{
                if(f[l]>f[r]){
                    f[l]-=f[r];
                    ans+=f[r];
                    r--;
                }
                else if(f[l]<f[r]){
                    f[r]-=f[l];
                    ans+=f[l];
                    l++;
                }
                else{
                    ans+=f[l];
                    l++,r--;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
