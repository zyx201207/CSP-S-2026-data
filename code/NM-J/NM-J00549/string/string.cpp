#include<bits/stdc++.h>
using namespace std;
int hui(string a){
    for(int i=0;i<a.size()/2;i++){
        if(a[i]!=a[a.size()-1-i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    string s;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s+=b;
        }
    }
    if(hui(s)){
        cout<<0;
        return 0;
    }
    int sum=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
