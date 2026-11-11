#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char ch;
string s;
int sum;
bool hw(string s,string c){
    bool f=true;
    for(int i=0;i<s.size();i++){
        if(s[i]!=c[i]){
            return false;
        }
    }
    return true;
}
string c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch;
        for(int j=0;j<a[i];j++){
            s+=ch;
        }
    }
    for(int j=s.size()-1;j>=0;j--)
        c+=s[j];
    if(hw(s,c)){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=c[i])
            sum++;
    }
    cout<<sum/2;
    return 0;
}
