#include<bits/stdc++.h>
using namespace std;
int n,r,l[200010];
long long ans;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n;
    for(int i=1;i<=n;i++)cin>>l[i]>>c[i];
    for(int i=1;i<=n;i++){
        if(i>=r)break;
        while(l[i]&&i<r){
            if(l[i]>=l[r]){
                if(c[i]!=c[r])ans+=l[r];
                l[i]-=l[r--];
            }
            else if(l[i]<l[r]){
                if(c[i]!=c[r])ans+=l[i];
                l[r]-=l[i];
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
