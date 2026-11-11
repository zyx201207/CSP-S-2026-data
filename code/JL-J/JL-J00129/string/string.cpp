#include <bits/stdc++.h>
using namespace std;
int main(){
        freopen(string.in,"r","stdin");
        freopen(string.out,"w","stdout");
        long long  a,b=0;
        cin>>a;
        string w;
        for(int i=0;i<a;i++){
            long long s;
            char z;
            cin>>s>>z;
            b+=s;
            for(int j=0;j<s;j++){
                w+=z;
            }
        }
        long long e=0;
        for(int i=0,j=b-1;i<j;i++,j--){
            if(w[i]!=w[j]){
                e++;
                w[j]=w[i];
            }
        }
        cout<<e;
        return 0;
        }
