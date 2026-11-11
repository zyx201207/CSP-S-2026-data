#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    int ans = 0;
    string a;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int num;
        string s;
        cin >> num >> s;
        for(int j = 1;j<= num;j++){
            a += s;
        }
    }
    for(int i = 0;i < (a.length()) * 0.5;i++){
        if(a[i] != a[a.length() + 1 - i]){
			a[a.length() + 1 - i] = a[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}
