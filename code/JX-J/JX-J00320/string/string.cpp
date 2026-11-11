#include <bits/stdc++.h>
using namespace std;
int ishui(string a){
    int si=a.size()-1;
    for(int i=0;i<si;i++){
        if(a[i]==a[si-i]) continue;
        else return 0;
    }
    return 1;
}
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    int n;
    string s;
    cin>>n;
    long long  ny[n+2];
    char a[n+2];
    for(int i=0;i<n;i++){
        cin>>ny[i]>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<ny[i];j++){
            s+=a[i];
        }
    }
    if(ishui(s)==1) cout<<0;
    else{
        long long siz=s.size()-1,cnt=-1;
        for(int i=0;i<siz;i++){
            if(a[i]==a[siz-i]) continue;
            else cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
