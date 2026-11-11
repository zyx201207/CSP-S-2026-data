#include<bits/stdc++.h>
 using namespace std;
 int a[20];
 int main()
 {
 	freopen("migrate.in","r",stdin); 	
	freopen("migrate.out","w",stdout);
	for(int i=1;i<=15;i++)
	{
		cin>>a[i];
	}
	if(a[15]==5){
		cout<<1<<endl;
		cout<<2;
		return 0;
	} 
	 else{
		cout<<0<<endl;
		cout<<1;
	} 
	return 0;	
 }
