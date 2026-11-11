#include <bits/stdc++.h>
using namespace std;
string s = "";
int n;
int a[200010];
char c[200010];
long long f(string x){
    long long cnt = 0;
    long long i = 0,j = x.size() - 1;
    while(i <= j){
        if(x[i] != x[j]){
            cnt++;
        }
        i++;
        j--;
    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= a[i];j++){
            s += c[i];
        }
    }
    long long ans = f(s);
    cout<<ans;
    return 0;
}
