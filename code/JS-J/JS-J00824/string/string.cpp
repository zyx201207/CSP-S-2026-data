#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005],sum=-1,ans=0;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        char x;
        cin >> a[i] >> x;
        for(int j = sum+1;j<=sum+a[i];j++) s[j] = x;
        sum+=a[i];
    }
    for(int i=sum/2;i>=0;i--){
        if(s[i]!=s[sum-i]) ans++;
    }
    cout << ans;

    return 0;
}
