#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e6+10;
string c1,s1,c2,s2;
char gcd(char x){
	return x-'0';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1=0,b1=0;
	for(int i=0;i<c1.size();i++){
		a1=a1*10+gcd(c1[i]);
	}
	for(int i=0;i<c2.size();i++){
		b1=b1*10+gcd(c2[i]);
	}
	if(a1==b1){
	   int a2=0,b2=0;
       for(int i=0;i<s1.size()-1;i++){
           a2=a2*10+gcd(s1[i]);
       }
       for(int i=0;i<s2.size()-1;i++){
           b2=b2*10+gcd(s2[i]);
       }
       if(a2==b2){
       	  char a3,b3;
          a3=s1[2];
          b3=s2[2];
          if(a3<='C'&&b3<='C'){
             if(a3==b3+1||a3+1==b3) cout<<"1111";
             else cout<<"1110";

          }
          else if(a3>='D'&&b3>='D'){
                  if(a3==b3+1||a3+1==b3) cout<<"1111";
                  else cout<<"1110";
               }
               else cout<<"1100";
       }
       else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}