#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,b,c,d,s,s1,s2,s3,i;
	cin>>n>>m;
	cin>>a>>b>>c>>d;
	
	if(a and b>a and c)
		s=a and b;
		else{
			s=a and c;
		}
		if(s>a and d)
		 s1=s;
		else{
			s1=a and b;
		}
		if (s1> b and c)
		 s2=s1;
		else{
			 s2=b and c;
		}
		if(s2>b and d)
		 s3=s2;
		else{
			 s3=b and d;
		}
		cout<<s3;
	
	return 0;
}