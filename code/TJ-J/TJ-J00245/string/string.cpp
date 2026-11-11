#include<bits/stdc++.h> 
using namespace std;
int x[1000000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int sum=0;
	int a=0;

	int n;
	cin>>n;
	
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>x[i]>>s[i];
	 	sum=sum+x[i];
	    
	 	
	 }
	 for(int i=1;i<=n;i++)
	 {
	 	if(s[i-1]!=s[i])
	 	{
	 		a=1;
		}
	
	}
	if(a=0)
	{
		cout<<0;
	}
	else
	{
		cout<<sum/2;
	}
	 
	
	
	return 0;
}
