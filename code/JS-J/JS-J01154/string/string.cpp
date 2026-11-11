#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt = 0,a[200010] = {0};
    char b[200010] = {0};
    string s = "";
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>b[i];
        for(int j = 0;j < a[i];j++){
            s += b[i];
        }
        a[i] = a[i] + a[i - 1];
    }
    if(n%2){
        int mid = (a[n] + 1) / 2;
        for(int i = 1;i <= (a[n] - 1) / 2;i++){
            if(s[mid+i] != s[mid-i]){
                cnt++;
            }
        }
    }
    else{
        int mid = a[n] / 2;
        for(int i = mid;i >= 1;i--){
            if(s[i] != s[a[n] - i]){
                cnt++;
            }
        }
    }
    cout<<s<<" "<<cnt;
    return 0;
}
