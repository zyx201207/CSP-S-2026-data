#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long ans =0;
    cin>>n;
    int s[1001];
    for(int i =0;i<n;i++){
        int a;
        string c;
        cin>>a;
        for(int j =0;j<a;j++){
            cin>>s[j];
        }long long len = n*a;
        for(long long m =0;m<=len;m++){
            for(long long j =len;j>=0;j--){
                if(s[m]!=s[j]){
                    s[j]=s[m];
                    ans++;
                }else ans =0;
        }
    }
}
    cout<<ans;
    return 0;
}
