#include<bits/stdc++.h>
using namespace std;
int n;
long long a,l,t;
char b;
string s;
int main(){
    freopen("string","r",stdin);
    freopen("string","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int o=0;o<a;o++){
            s+=b;
            l++;
        }
    }
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i])t++;
    }
    cout<<t;
    return 0;
}
