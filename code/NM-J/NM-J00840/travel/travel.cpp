#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("tracel.out","w",stdout);
	int a,b;
	int a1,a2,q,b1,b2,w;
	cin>>a>>a1>>a2>>q>>b>>b1>>b2>>w;
	int c=(a1-'0')*10+(a2-'0');
	int d=(b1-'0')*10+(b2-'0');	
	if(a==b) cout<<1;
	         else
			 {cout<<0000;
			 return 0;
			 }
			  
	if(c==d) cout<<1;
			 else cout<<0;
	if(((q=='A'||q=='B'||q=='C')&&(w=='A'||w=='B'||w=='C'))||((q=='D'||q=='E')&&(w=='D'||w=='E'))){
	
		cout<<1;
		if(abs(q-w)==1) {
			cout<<1;
			return 0;
		  }
		}else{
			cout<<0;
		}
		cout<<0;
		return 0;
}
