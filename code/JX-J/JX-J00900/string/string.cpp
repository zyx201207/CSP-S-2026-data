#include<bits/stdc++.h>
using namespace std;
bool fz(string a){
    string b=a;
    reverse(b.begin(),b.end());
    if(a==b){
        return true;
    }
    return false;
}
int fzs(string c){
    long long sum=0;
    int l=0,r=c.size()-1;
    while(l<r){
        if(c[l]!=c[r]){
            sum++;
            l++;
            r--;
        }
    }
    return sum;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long s;
    char a;

    string x="";
    for(int i=1;i<=n;i++){
        cin>>s>>a;
        for(int j=1;j<=s;j++){
            x+=a;
        }
    }
    if(fz(x)){
        cout<<0;
        return 0;
    }
    cout<<fzs(x);
    return 0;
}
