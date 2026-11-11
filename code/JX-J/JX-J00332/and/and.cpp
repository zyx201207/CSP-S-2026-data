#include <bits/stdc++.h>
using namespace std;

string a[214514];
string to_2(int sum){
    string k = "";
    for(;sum != 0;sum/=2){
        k = (char)(sum%2+'0')+k;
    }
    return k;
}
bool cmp(string q,string p){
    return q.size()>p.size();
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin >> n >> m;
    int w,s = 0;
    for(int i = 1;i <= n;i++){
        cin >> w;
        if(s<w){
            s = w;
        }
    }
    cout << s;
    return 0;
}
