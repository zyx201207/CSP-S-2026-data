#include<bits/stdc++.h>
using namespace std;
string s,n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,b,cnt=0,f=0,cut=0;
    char c;
    for(int i=1;i<=a;i++){
        cin>>b>>c;
        for(int j=1;j<=b;j++){
            f+=1;
            s[f]+=c;
        }
    }
    int u=s.size();
    int z=s.size()/2;
    for(int i=1;i<=z;i++){
        if(s[i]==s[z-i+1] and cut==z){
            cout<<"0";
        }
        else{
            cut++;
        }
    }
    for(int i=z/2;i<=z;i++){
        if(s[i]!=s[z-i+1]){
            s[z-i+1]!=s[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
