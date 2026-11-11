#include <bits/stdc++.h>
using namespace std;
int a;
string s;
bool huiwen(string m){
    int si=m.size();
    for(int i=0;i<m;i++){
        if(m[i]==m[si-i]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}
int h(string n){
    int l=n.size(),step=0;
    if(huiwen(n)) return step;
    for(int i=0;i<l/2;i++){
        if(n[i]==n[l-i]){
            continue;
        }else{
            n[l-i]=n[i];
            step+=1;
        }
    }
    return step;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    int b[a+5];
    string c[a+5];
    for(int i=0;i<a;i++){
        cin>>b[i]>>c[i];
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b[i];j++){
            s+=c[i];
        }
    }
    cout<<h(s);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
