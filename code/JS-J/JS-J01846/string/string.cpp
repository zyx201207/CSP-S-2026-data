#include <bits/stdc++.h>
using namespace std;
long long n,ans,sum;
string s,c;
int a[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=sum;j<sum+a[i];j++){
            s[j]=c[i];
        }
        sum+=a[i];
    }
    for(int i=0;i<sum/2;i++){
        for(int j=sum-1;j>=sum/2+1;j--){
            if(s[i]!=s[j]){
                ans++;
            }
            break;
        }
    }
    cout<<ans;
    return 0;
}
