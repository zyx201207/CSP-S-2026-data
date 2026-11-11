#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin >> x >> c;
        for(int j=1;j<=x;j++){
            s+=c;
        }
    }
    int len=s.size();
    int cnt=0;
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
