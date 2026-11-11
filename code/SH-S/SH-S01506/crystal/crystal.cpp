#include<bits/stdc++.h>
using namespace std;
int main()
{
		freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n>=3)
	{
	  if(n=3)
	  	{
		  int a1 , a2 , a3;
	  	cin>>a1>>a2>>a3;

	  	if((a1>a2)&&(a1>a3))
	  	{
	  	if(a1-a2>a1-a3)	
	  	 {
	  	   if((m-(a1-a3))>=0)
			 {
			 	int s=m-(a1-a3);
			 	if(s-(a1-a3)>=0)
			 	{
			 		cout<<"3"<<endl;
				 }
				else
				cout<<"2"<<endl;
				 }	
				 
		 }
		 else{
		 	if(a1-a2<a1-a3)	
	  	 {
	  	   if((m-(a1-a2))>=0)
			 {
			 	int s=m-(a1-a2);
			 	if(s-(a1-a2)>=0)
			 	{
			 		cout<<"3"<<endl;
				 }
				else
				cout<<"2"<<endl;
				 }	
				 }	
		 }
		}
		else{
			if((a2>a1)&&(a2>a3))
	  	{
	  	if(a2-a1>a2-a3)	
	  	 {
	  	   if((m-(a2-a3))>=0)
			 {
			 	int s=m-(a2-a3);
			 	if(s-(a2-a3)>=0)
			 	{
			 		cout<<"3"<<endl;
				 }
				else
				cout<<"2"<<endl;
				 }	
			}
		 }
		 else{
		 	if(a2-a1<a2-a3)	
	  	 {
	  	   if((m-(a2-a1))>=0)
			 {
			 	int s=m-(a2-a1);
			 	if(s-(a2-a1)>=0)
			 	{
			 		cout<<"3"<<endl;
				 }
				else
				cout<<"2"<<endl;
				 }	
				 }	
		 }
		}
		}
	
	  else{
	  	int a1,a2,a3;
	  	cin>>a1>>a2>>a3;
	  	if(a3-a2>a3-a1)	
	  	 {
	  	   if((m-(a3-a1))>=0)
			 {
			 	int s=m-(a3-a1);
			 	if(s-(a3-a1)>=0)
			 	{
			 		cout<<"3"<<endl;
				 }
				else
				cout<<"2"<<endl;
				 }	
				 
		 }
		 else
		 {
		 	if(a3-a2<a3-a1)	
	  	 {
	  	   if((m-(a3-a2))>=0)
			 {
			 	int s=m-(a3-a2);
			 	if(s-(a3-a2)>=0)
			 	{
			 		cout<<"3"<<endl;
				 }
				else
				cout<<"2"<<endl;
				 }	
				 }	
		 }
		}
	  }
}
 else
	{
	cin>>a[n];
	for(int i=1;i<=n;i++)
	{
	int a[n]=a;	
	}
	int s=min(a[n]-a);
	if(s<=m)
	{
		for(int j=1;j<=n-1;j++)
		cout<<j<<endl;
	}


    cout<<a[n]<<endl;
}
}

	return 0;
}
