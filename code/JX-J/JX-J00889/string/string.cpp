#include <bits/stdc++.h>;
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        sum+=a;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    long long ans=0;
    for(int i=0;i<sum/2;i++){
        if(s[i]!=s[sum-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
