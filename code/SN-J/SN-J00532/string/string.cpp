#include<iostream>
#include<string>  
using namespace std;
int main(){
	int n;
	cin>>n;
	int zdjd[1005];
	string a[1005];
	char kskbl[1005];
	for(int i=0;i<=n-1;i++)
	{
		cin>>zdjd[i];
		for(int j=1;j<=zdjd[i];j++)
		{
			cin>>kskbl[i];
			for(int l=1;l<=n;l++)
			{
				cin>>a[i];
			}
		}	
	}
	cout<<a[0];
}
