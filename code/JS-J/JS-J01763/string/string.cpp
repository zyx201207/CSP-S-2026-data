#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s=" ";
    for(int i=1;i<=n;i++){
        long long m;
        cin >> m;
        char a;
        cin >> a;
        for(int j=1;j<=m;j++){
            s+=a;
        }
    }
    long long num=s.size();
    long long ans=0;
    for(int i=1;i<num/2;i++){
        if(s[i]!=s[num-i]){
            ans++;
        }
    }
    cout << ans;

    return 0;
}
