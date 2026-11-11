#include <iostream>

using namespace std;

int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   int a,b,t,o,k,h; 
   string c,d,n,m;
   cin >> a >> b;
   for(int i = 0; i <=3; i++){
   		cin >> c[i] >> d[i];
   } 
   if(a == b){
        t += 1;
   }else{
        t = 0;
   }
   for (int i = 0; i <= 3;i++){
        n = c[i];
        m = d[i];
   }
   if (n[1] == m[1]){
        o += 1;
   }else{
        o = 0;
   }
   if (n[2] == 'A' || m[2] =='B'&& n[2] == 'B' || m[2] == 'C'&& n[2] == 'C' || m[2] == 'B'&& n[2] == 'A' || m[2] == 'C'&&n[2] == 'C' || m[2] == 'A'&&n[2] == 'B' || m[2] == 'A'){
        k += 1;
   }else if(n[2] == 'D' || m[2] == 'F' && n[2] == 'F' || m[2] == 'D'){
        k += 1;
   }else{
        k = 0;
   }
   if (n[2] == 'B' || m[2] == 'C' && n[2] == 'A' || m[2] == 'B' && n[2] == 'C' || m[2] == 'B'&&n[2] == 'B' || m[2] == 'A'){
       h += 1;
   }else if (n[2] == 'D' || m[2] == 'F' && n[2] == 'F' || m[2] == 'D'){
       h += 1;
   }else{
       h = 0;
   }

    cout << t,o,k,h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
