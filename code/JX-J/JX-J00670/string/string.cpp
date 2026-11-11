#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    int c=0;
    for(int i=0;i<s.size();i++){
        char s1=s[s.size()-i-1];
        if(s1!=s[i]){
            c++;
        }
    }
    cout<<c/2;
    return 0;
}
