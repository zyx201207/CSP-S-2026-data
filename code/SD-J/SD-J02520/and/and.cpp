#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int x,y,z,a,b=0,c;
	cin>>x;
	for(int i;i<=x;i++){
		cin>>a;
		if(a>b){
			continue;
		}
		else{
			c=a;
			a=b;
			b=c;
		}
	}
	cout<<a;
	return 0;
} 
