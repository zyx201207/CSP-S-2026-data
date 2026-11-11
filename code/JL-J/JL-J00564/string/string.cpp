#include <bits/stdc++.h>
using namespace std;

int n,ss,o;
string s;
int d;
char ch;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d>>ch;
        for(int i=1;i<=d;i++){
            s+=ch;
        }
        //ss+=d[i];
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            o++;
        }
    }
    cout<<o;
    return 0;
}
