#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n[101],x[101],m[101],s=0,b,k=0,h=1;
	cin>>b;
	for(int i=1;i<=b;i++)
	{
		cin>>n[i]>>m[i]; 
		s=s+n[i];
	}
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=n[i];j++){
			x[h]=m[i];
			h+=1;
		}
	}
	s=s/2;
	if(s%2!=0)
	{
		for(int i=1;i<=s;i++)
		{
			if(x[i]!=x[i+s+1])
				k+=1;
		}
	}
	if(s%2==0)
	{
		for(int i=1;i<=s;i++)
		{
			if(x[i]!=x[i+s])
				k+=1;
		}
	}
	cout<<k<<endl;
	fclose(stdin);
	fclose(stdin);
	return 0;	
}
