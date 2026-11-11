#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and2.in","r",stdin);
	freopen("and2.out","w",stdout);
	int n,m,a,i,c,z;
	cin>>n>>m;
	int s[n];
	for(int f=0;f<n;f++){
		cin>>i;
		c++;
		for(int f=1;f<=c;f++){
			z=i&m;
			if(z>=i){
				a=z;
			}else{
				a=i;
			}
		}
	}
	
	cout<<a;
	return 0;
}
