#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin >> n;
    string s="";
    for(int i=1;i<=n;i++){
        int a;char b;cin >> a >> b;
        while(a--){
            s+=b;
        }
    }
    int l=s.size()/2;
    string q="";
    for(int i=0;i<l;i++){
        q+=s[i];
    }
    int num=0;
    if(s.size()%2==0){
        for(int i=s.size()-1;i>=l;i--){
            if(q[i]!=s[i]){
                num++;
            }
        }
    }
    else{
        for(int i=s.size()-1;i>l;i--){
            if(q[i]!=s[i]){
                num++;
            }
        }
    }
    cout << num;


    return 0;
}

