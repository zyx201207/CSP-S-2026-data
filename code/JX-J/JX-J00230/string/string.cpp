#include<bits/stdc++.h>
using namespace std;
int n , ji = 1 , cnt = 0;
long long a[10000005];
char s[10000005];
string m;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>> n;
    for(int i = 1;i <= n;i++){
        cin>> a[i];
        cin>> s[i];
        for(int j = 1;j <= a[i];j++){
            m[ji] = s[i] - '0';
            ji++;
        }
    }
    for(int i = 1;i <= n;i++){
        if(m[i] != m[n+1-i]){
            cnt++;
            m[n-i] = m[i];
        }
    }
    cout<<cnt;
    return 0;
}
