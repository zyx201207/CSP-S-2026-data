#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
string huiwen(string s){
    string ss={ };
    for(int i=s.size()-1;i>=0;i--){
        ss+=s[i];
    }
    return ss;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int step=0;
    int n;
    cin>>n;
    string s={ };
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    for(int i=1;i<=a[i];i++){
        s+=c[i];
        }
    }
    if(huiwen(s)==s){
        cout<<0;
    }
    return 0;
}

