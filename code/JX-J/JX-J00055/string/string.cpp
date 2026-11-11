#include<bits/stdc++.h>
using namespace std;
string s;
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans = 0;
    int n;
    long long m;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin >> m;
        cin >> a;
        for(int j = 1;j<=m;j++){
            s += a;
        }
    }
    int mid = (s.size()-1)/2;
    for(int i = 0;i<mid;i++){
        if(s[i] != s[s.size() - i - 1]){
            ans++;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
