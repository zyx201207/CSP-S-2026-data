#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    long long n,a[200005],max1 = 0,cnt = 0,max2 = 0,r = 0;
    int f,g;
    string s,s1;
    char q;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> q;
        r += a[i];
        if(a[i] >= max2) max2 = a[i];
        for(int j = 1;j <= a[i];j++){
            s +=q;
        }
        for(int j = a[i];j>=1;j--){
            s1 +=q;
        }
    }
    f = s.size() - max2;
    for(int i = 1;i <= s.size();i++){
        if(s[i] == s1[i]){
            cnt++;
            s[i] == '0';
            s1[i] == '0';
            s[s.size() - i + 1] = '0';
            s1[s1.size()-i+1] = '0';
        }else{
            break;
        }
    }
    for(int i = 1;i <= s.size();i++){
        if(s[i] >='a'&&s[i]<='z'){
            if(a[i] >= max1) max1 = a[i];
        }
    }
    g = s.size() - max1 - cnt * 2;
    if(s == s1) g = 0;
    cout << r - max2;
  //cout << min(f,g);
    return 0;
}
