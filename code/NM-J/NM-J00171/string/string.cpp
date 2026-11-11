#include<bits/stdc++.h>
using namespace std;
bool shifouduichen(string s,int n){
    string s1;
    int o=0;
    for(int i=n-1;i>n/2;--i){
        s1.insert(o,s.substr(i-1,i));
        ++o;
    }
    if(s.substr(0,n/2)==s1){
        return true;
    }
    return false;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s1;
    int a,n,m=0;
    string c;
    cin>>n;
    int a1[n];
    for(int i=0;i<n;++i){
        cin>>a>>c;
        a1[i]=a;
        for(int o=m;o<m+a;++o){
            s1.insert(o,c);
        }
        m+=a;
    }
    int s;
    s=0,a=0;
    for(int i=m-1;i>-1;--i){
        if(shifouduichen(s1,m)){
            cout<<a;
            return 0;
        }else{
            s1.erase(i,i);
            s1.insert(i,s1.substr(s,s));
            ++s;
            ++a;
        }
    }
    return 0;
}
