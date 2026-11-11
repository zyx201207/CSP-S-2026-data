#include<bits/stdc++.h>
using namespace std;
long long n, t;
int a[10000005];
string s, s1;
char c[10000005];
bool f = true;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> c[i];
        t += a[i];
        s += a[i] + '0';
        s += c[i];
    }
    for(int i = 0;i < n;i++){
        if(c[i] != c[0]) f = false;
    }


    if(f){
        cout << "0";
        return 0;
    }
    for(int i = s.size() - 1;i >= 0;i -= 2){
        s1 += s[i - 1];
        s1 += s[i];
    }
    if(s1 == s){
        cout << "0";
        return 0;
    }
    cout << t / 2;
	return 0;
}
