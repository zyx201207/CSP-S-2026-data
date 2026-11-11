#include <bits/stdc++.h>
using namespace std;

long long a[200001];
char b[200001];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
    }
    string s = "";
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= a[i];j++){
            s+=b[i];
        }
    }
    long long start = s.length()/2+1;
    if(s.length()%2 == 0){
        for(int i = 0;i < start;i++){
            if(s[start-i-2] != s[start+i-1]){
                ans++;
            }
        }
    }
    else{
        for(int i = 0;i < start;i++){
            if(s[start-i-2] != s[start+i]){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
