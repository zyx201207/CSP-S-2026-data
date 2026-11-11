#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  int main()
  {
	  int n;
	  cin >> n;
	  int [i][j];
    string c1,s1,c2,s2;
     int a,b,c,d = 0;
     for(int i = 0;i <= n;i++)
     {
     if(c1[i] = c2[i])
     {
     cout << "1";
     a = 1;
     }
   else
   {
   cout << "0";
   a = 0;
   break;
   }
   if(s1[i] = s2[i])
   {
   cout << 1;
   b = 1;
   }
 else 
 {
   cout << "0";
   b = 0;
   break;
 }
 if(s1[i] = s2[i] && s1[j] = s2[j])
 {
 cout << "1";
 c = 1;
 }
 else 
 {
 cout << 0;
 c = 0;
 break;
 }
 for(s1[j] - '1' >= 'A'|| s1[j] + '1' <= 'F')
 {
 if(s1[j] = s2[j])
 {
 cout << "1";
 d = 1;
 }
 else 
 {
 cout << "0";
 d = 0;
 break;
 }
 }
 cout << a << b << c << d << endl;
}
 return 0;
  }
