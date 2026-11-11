#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2;
string res;
bool judge(char a,char b){
    if((a == 'A' || a == 'B' || a == 'C' )&&(b == 'A' || b == 'B' || b == 'C'))return true;
    if((a == 'D' || a == 'F') && (b == 'D' || b == 'F'))return true;
    return false;
}
bool sjudge(char x,char y){
    char a = x,b = y;
    x = min(a,b);
    y = max(a,b);
    if((x == 'A' && y == 'B') || (x == 'B' && y == 'C') || (x == 'D' && y == 'F'))return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   cin >> a1 >> a2 >> b1 >> b2;
   if(a1 == b1)res = res + '1';
   else res = res + '0';
   int p1 = (a2[0] - '0') * 10 + (a2[1] - '0');
   int p2 = (b2[0] - '0') * 10 + (b2[1] - '0');
   if(p1 == p2 && a1 == b1)res = res + '1';
   else res = res + '0';
   char x = a2[2],y = b2[2];
   if(res == "11" && judge(x,y))res = res + '1';
   else res = res + '0';
   if(sjudge(x,y) && res == "111")res = res + '1';
   else res = res + '0';
   cout << res << endl;
   return 0;
}
