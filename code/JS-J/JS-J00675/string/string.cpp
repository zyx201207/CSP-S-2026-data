#include <bits/stdc++.h>
using namespace std;
int n,j;
string s;
int a[200005];
long long ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    j=n;
    for(int i=1;i<j;i++){
        if(c[i]!=c[j]){
            if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                i--;
                j--;
            }else{
                ans+=a[i];
                a[j]-=a[i];
            }
        }else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                i--;
                j--;
            }else{
                a[j]-=a[i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
