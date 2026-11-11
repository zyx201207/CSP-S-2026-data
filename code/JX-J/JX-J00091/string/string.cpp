#include <bits/stdc++.h>
using namespace std;
struct duan{
    int len;
    char cont;
    long long left;
    long long right;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    //int cnt = 0;
    long long sum = 0;
    cin >> n;
    string s;
    while(n--){
        int k;char c;
        cin >> k >> c;
        for(int i = 1;i <= k;i++){
            s += c;
        }
        sum += k;
    }
    long long mid = sum/2;
    long long diff=0;
    string cop = s;
    reverse(s.begin(),s.end());
    for(int i = 0;i < s.size();i++){
        if (cop[i] != s[i]){
            diff++;
        }
    }
    cout << diff/2;
}
