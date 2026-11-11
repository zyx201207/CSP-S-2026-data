#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,s,ans,a1,a2;
int a[200005];
char c[200005];
char c1;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        s+=a[i];
    }
    int t;
    for(int i=1;i<=n;i++){
        t+=a[i];
        if(t+a[i+1]>s/2){
            a1=s/2-t;
            a2=a[i+1]-a1;
        }
    }
    int i=1,j=n;
    while(i<j){
        if(c[i]!=c[j]){
            if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }else if(a[i]==a[j]){
                ans+=a[i];
                i++;
                j--;
            }else{
                ans+=a[i];
                a[j]-=a[i];
                i++;
            }
        }else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else if(a[i]==a[j]){
                i++;
                j--;
            }else{
                a[j]-=a[i];
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}