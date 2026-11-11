#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans = 0;
long long k = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        int a;
        string s1;
        cin>>a>>s1;
        for(int j=1;j<=a;j++){
            s += s1;
            k++;
        }
    }for(long long i = 0;i<k/2;i++){
        if(s[i]!=s[k-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
