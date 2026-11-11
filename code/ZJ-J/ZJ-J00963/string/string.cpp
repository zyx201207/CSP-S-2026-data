#include<bits/stdc++.h>
using namespace std;
int main()
 {
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	/*
 	int n;
	int huiwen=0;
 	int c=1;
 	cin>>n;
 	string b[100000];
 	int a[2*n];
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 		string s;
 		cin>>s;
 		for(int j=1;j<=a[i];j++)
 		{
 			b[c]=s;
 			c++;
		 }
	 }
 	for(int i=1;i<=c/2;i++)
 	{
 		if(b[i]!=b[c-i])
 		{
 			huiwen++;
		 }
	 }
 	cout<<huiwen;
 	*/
 	
 	long long n;
	long long huiwen=0,huiwen1=0,huiwen2=0;
	//cout<<huiwen;
 	cin>>n;
 	long long c=n;
 	long long b=1;
 	string a1,a2,a3;
 	long long a[n+10];
 	string d[n+10];
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 		//cout<<a[i];
 		cin>>d[i];
 		//cout<<'d[i]';
	 }
	 for(int i=1;i<=n;i++){
	 
		
		 	if(c<=b){
	 		break;
		 }
	 	if(d[b]==d[c])
	 	{
	 		if(a[b]>a[c])
	 		{
	 			a[b]=a[b]-a[c];
				c--;
			 }else{
			 if(a[b]<a[c])
	 		{
	 			a[c]=a[c]-a[b];
	 			b++;
			 }else{
			 if(a[b]==a[c])
			 {
			 	b++;
			 	c--;
			 }
		}
		}
		 }else{
		 		if(a[b]>a[c]){
	 				a[b]=a[b]-a[c];
	 				huiwen=huiwen+a[c];
	 				//cout<<huiwen<<endl;
	 				c--;
			 }else{ if(a[b]<a[c]){
	 			a[c]=a[c]-a[b];
	 			huiwen=huiwen+a[b];
	 			//cout<<huiwen<<endl;
	 			b++;
			 }else{
			 if(a[b]==a[c])
			 {
			 	//cout<<huiwen<<endl;
			 	huiwen=huiwen+a[c];
			 	//cout<<huiwen<<endl;
			 	b++;
			 	c--;
			 
			 		}
				}
			}
		 }
	 
 }
 
 cout<<huiwen;
 
 	
 	return 0;
 }

