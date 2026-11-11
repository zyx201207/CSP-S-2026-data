#include <bits/stdc++.h>
using namespace std;
string r(string k){
    string h;
    for(int i=k.size();i>=0;i--){
        h+=k[i];
    }
    return h;
}
bool m(string a,string b){
    int g=0;
    for(int i=0;i<b.size();i++){
        if(b[i]==a[i]){
            g++;
        }
    }
    if(g==b.size()){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cut=0;
    string k="";
    cin>>n;
    while(n--){
        long long l;
        string m;
        cin>>l;
        cin>>m;
        for(int i=0;i<l;i++){
            k+=m;
        }
    }
    string b="";
    for(int i=1;i<k.size();i++){
        b=r(k);
        if(m(b,k)){
            cout<<cut;
            return 0;
        }
        if(k[i]!= k[1]){
            k[i-1]=k[1];
            cut++;
        }
    }
    if(cut==0){
        cout <<0;
    }else{
        cout<<cut-1;
    }
    return 0;
}
