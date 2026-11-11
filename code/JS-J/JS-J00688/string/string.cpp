#include<bits/stdc++.h>
using name space;
int main(){
freopen("string.in", "r", stdin);
freopen("string.out", "w", stdout);
int n, a[100000], c[100000], sm = 0;
int ci = 0, x = 0;
scanf("%d", &n);
if(n = 1){
cout << 0;
return 0;
}for(int i = 0; i < n; n ++){
    cin >> a[i] >> c[i];
}for(int i = 0; i < n; n ++){
    if(c[i] == c[n - i]){
    x += 0;
    }else{
    x += 1;}

}for(int i = 0; i < n; n ++){
    sm += a[i];
}
if(x == 0){
cout << 0;
}
else{
cout << sm / 2;}
return 0;
}
