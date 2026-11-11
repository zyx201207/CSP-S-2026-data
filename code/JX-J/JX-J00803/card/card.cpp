#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int c[300010];
string s;
string too(char u){
    string t="";
    int t1=u-'0';
    t.append(to_string(t1));
    return t;
}
int cs(string o){
    for(int i=0;i<s.length();i++){
        if(too(s[i])==o){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        s="";
        for(int i=j;i<n;i++){
            string as=to_string(a[i]);
            if(cs(as)!=-1){
                s.erase(cs(as),s.length()-cs(as));
            }
            s.append(as);
        }
        for(int i=0;i<s.length();i++){
            c[s[i]-'0']++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    //zhushi
    return 0;
}
