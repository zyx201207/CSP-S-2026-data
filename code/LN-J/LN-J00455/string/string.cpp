#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200010];
char c[200010];
long long sum;
long long ans;
string s;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        cin>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    //cout<<s<<" "<<sum;
    for(int i=0;i<sum/2;i++){
        if(s[i]!=s[sum-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
