#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
stack<char> s;
long long meb[N];
string s1;
char a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> meb[i] >> a[i];
        for(int j = 0;j < meb[i];j++){
            s.push(a[i]);
            s1 = s1 + a[i];
        }
    }

    long long ans = 0;
    for(int i = 0;i <= n/2;i++){
      char n = s.top();
      s.pop();
      if(n != s1[i]){
        ans++;
      }
    }
      cout << ans;
   return 0;
 }

