#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans;
char c[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i<j){
        if(c[i]!=c[j]){
            if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j--;
                continue;
            }
            if(a[i]==a[j]){
                ans+=a[i];
                i++;
                j--;
                continue;
            }
            if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                i++;
                continue;
            }
        }
        else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
                continue;
            }
            if(a[i]==a[j]){
                i++;
                j--;
                continue;
            }
            if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}
