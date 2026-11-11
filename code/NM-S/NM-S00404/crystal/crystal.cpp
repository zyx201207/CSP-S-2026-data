#include <bits/stdc++.h>
using namespace std;
long long n,m,a,b,c,d,e;
int f;
int main()
{
	cin>>n;
	for (int i=0;i<=n;i++)
	{
		cin>>a>>b>>c>>d>>e;
		if (a<b){
			a+1;
	      }
		if(a=b){
			f++;
			}
		if (b<c){
			b+1;
		}	
		if(b=c){
			f++;
			}
		  
		if (c<d){
			c+1;
		}	
		if(c=d){
			f++;
			}
		  
		if (d<e){
			d+1;
		}	
		if(d=e){
			f++;
			}
		  
	}
	cout<<f;
	return 0;
}
