#include<bits/stdc++.h>
using namespace std;
int n,a;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
  cin>>n>>a;
  int sum=0;
  for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=n;j++)
  	{
  		bool d=1;
  		if(d==1)
  		{
  			sum++;
		  }
		  else
		  {
		  	cout<<"0";
		  }
	  }
  }
  cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
