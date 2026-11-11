#include <bits/stdc++.h>
using namespace std;
int n,ai,b=0;
string s,c="false";
string ci,a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai>>ci;
		for(int j=i;j<=n;j++){
			a[j]=ci;
			}
		
		for(int j=1;j<=ai;j++){
			s+=ci;
	}
	}
	//cout<<s;
	for(int x=1;x<=n;x++){
		for(int y=x;y<=n;y++)
			if(a[y]==ci)
			
				c="true";
			else c="false";
				b++;
			
			
		}
				
		
	if(c=="false")
		cout<<b;
	
	if(c=="true")
		cout<<"0";
	
	
	
	
	
	
	return 0;
}
