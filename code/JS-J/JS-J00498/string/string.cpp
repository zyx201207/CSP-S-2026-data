#include<bits/stdc++.h>
using namespace std;
int cmp(string s){
    int sum=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[i+s.size()/2])sum++;
    }
    return sum;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n,x;
    cin>>n;
    char ffff;
    for(int i=1;i<=n;i++){
        cin>>x>>ffff;
        for(int j=1;j<=x;j++){
            s+=ffff;
        }
    }
    cout<<cmp(s);
    return 0;
}
