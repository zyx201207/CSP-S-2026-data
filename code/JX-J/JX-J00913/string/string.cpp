#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string l,s;
    long long int n,si=0,u=0,p=0;
    cin>>n;
    for(long long int i=0;i<n;i++){
        string a;
        long long int b;
        cin>>b>>a;
        for(long long int j=0;j<b;j++){
            l+=a;
            si++;
        }
    }
    if(si%2!=0){
        for(long long int i=si/2;i>=0;i--){
            s[u]=l[i];
            u++;
        }
        //cout<<5/2;2
        u=0;
        for(long long int i=si/2;i<si;i++){
            if(l[i]!=s[u])p++;
            u++;
        }
    }
    else{
        for(long long int i=si/2-1;i>=0;i--){
            s[u]=l[i];
            u++;
        }
        //cout<<5/2;2
        u=0;
        for(long long int i=si/2;i<si;i++){
            if(l[i]!=s[u])p++;
            u++;
        }
    }
    cout<<p;
    return 0;
}
