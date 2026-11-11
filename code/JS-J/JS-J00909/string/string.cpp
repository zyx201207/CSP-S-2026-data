#include<bits/stdc++.h>
using namespace std;
int a[200009],sum;
char c[200009];
long long ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        sum += a[i];
        for(int j = 1;j <= a[i];j++){
            s += c[i];
        }
    }
    string a,b;
    if(sum % 2 == 1){
        a = s.substr(0,sum / 2),b = s.substr(sum / 2 + 1,sum / 2);
    }
    else if(sum % 2 == 0){
        a = s.substr(0,sum / 2),b = s.substr(sum / 2,sum / 2);
    }
    reverse(b.begin(),b.end());
    for(int i = 0;i < (int)b.size();i++){
        if(a[i] != b[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
