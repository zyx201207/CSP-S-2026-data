#include <bits/stdc++.h>
using namespace std;
string a;
string l,r;
long long diff(const string& a,const string& b){
    long long res = 0;
    for(int i=0;i<a.size();i++){
        res += (long long)(a[i] != b[i]);
    }
    return res;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        char c;
        int k;
        cin >> k >> c;
        for(int j=1;j<=k;j++){
            a += c;
        }
    }
    long long all = a.size();
    if(all & 1){
        l = a.substr(0,all / 2);
        r = a.substr(all / 2 + 1,all / 2);
        // cout << l << ' ' << r;
        reverse(r.begin(),r.end());
        cout << diff(l,r);
    }
    else{
        l = a.substr(0,all / 2);
        r = a.substr(all / 2,all / 2);
        // cout << l << ' ' << r;
        reverse(r.begin(),r.end());
        cout << diff(l,r);
    }
}