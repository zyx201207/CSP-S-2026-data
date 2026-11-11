#include<bits/stdc++.h>
using namespace std;
int c[200005];
char a[200005];
int n;
string s;
bool check(){
    string x;
    for(int i=s.size()-1;i>=0;i--){
        x+=s[i];
    }
    if(s!=x) return 1;
    else return 0;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> c[i] >> a[i];
        for(int j=1;j<=c[i];j++){
            s+=a[i];
        }
    }
    int cnt=0,i=0;
    while(check()){
        s[s.size()-1-i]=s[i];
        cnt++;
        i++;
    }
    cout << cnt;
    return 0;
}
