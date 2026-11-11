#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin >> n;
int a[200005];
char b[200005];
long long num = 0;
for(int i = 1;i <= n;i++){
    cin >> a[i] >> b[i];
}
long long ans;
string str;
for(int i = 1;i <= n;i++){
    for(int j = 1;j <= a[i];j++){
        str = str+ b[i];
    }
}
long long len = str.length() - 1;
for(long long i = 0;i <= len / 2;i++){
    if(str[i] != str[len - i]){
        ans++;
    }
}


cout << ans;
return 0;
}
