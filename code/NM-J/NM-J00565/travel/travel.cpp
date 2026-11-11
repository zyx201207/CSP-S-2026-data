#include<bits/stdc++.h>
using namespace std;
char c1[3],s1[4],c2[3],s2[4];
int c1s,c2s,s1s,s2s;
int a,b,c,d,e,f,g,h;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout)
 scanf("%s",c1 + 1);
 scanf("%s",s1 + 1);
 scanf("%s",c2 + 1);
 scanf("%s",s2 + 1);
 a = c1[1] - '0';
 b = c1[2] - '0';
 c1s = a * 10 + b;
 c = c2[1] - '0';
 d = c2[2] - '0';
 c2s = c * 10 + d;
 e = s1[1] - '0';
 f = s1[2] - '0';
 s1s = e * 10 + f;
 g = s2[1] - '0';
 h = s2[2] - '0';
 s2s = g * 10 + h;
 if(c1s == s1s && c1s != 1 && c1s != 16 && s1s != 1) && s1s != 16){
 cout << 1;
 }
 else{
 cout << 0;
 }
 if(c2s == s2s){
 cout << 1;
 }
 else{
 cout << 0;
 }
 if((s1[3] != 'D' && s1[3] != 'F' && s2[3] != 'D' && s2[3] != 'F') || (s1[3] != 'A' && s1[3] != 'B' && s1[3] != 'C' && s2[3] != 'A' && s2[3] != 'B' && s2[3] != 'C')){
 cout << 1;
 }
 else{
 cout << 0;
 }
 if((s1[3] == 'A' && s1[3] == 'B')||(s1[3] == 'B' && s1[3] == 'C')||(s1[3] == 'D' && s1[3] == 'F')){
 cout << 1;
 }
 else{
 cout << 0;
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
