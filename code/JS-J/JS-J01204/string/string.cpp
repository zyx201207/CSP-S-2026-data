#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,l=1,r,f=0;
    long long ans=0,cur=0;
    char s='#';
    cin>>n;
    r=n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    while(l<=r){
        if(f==0){
            if(s!=c[l])ans+=min(a[l],cur);
            if(a[l]>=cur){
                cur=a[l]-cur;
                s=c[l];
                l++;
                f=1;
            }
            else{
                cur=cur-a[l];
                l++;
                f=0;
            }
        }
        else{
            if(s!=c[r])ans+=min(a[r],cur);
            if(a[r]>=cur){
                cur=a[r]-cur;
                s=c[r];
                r--;
                f=0;
            }
            else{
                cur=cur-a[r];
                r--;
                f=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
