#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b,c = 1,d[500860],e[500860],f[500860],g = 1;
    cin >>a>>b;
    for(int i = 1;i<=a;i++){
        cin >>d[i];}
    for(int i = 1;i<=b;i++){
    for(int j = 0;j<a;j++){
        e[c] = d[i];
        f[e[c]]++;
        if(f[e[c]]>1){
            d[i+g] = e[c];
            g++;
}}
return 0;}
