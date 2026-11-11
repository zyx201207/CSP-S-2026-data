#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	cin>>n;
	int sum=0;
	char arr[n];
	string s;
	for(int i=1;i<=n;i++){
		cin>>a>>arr[i];
		s+=arr[i];
		sum+=a; 
	}
	for(int i=0;i<=n;i++)
	{
		if(s[i]==arr[i+1]){
			cout<<0;
			return 0;
		}	
		else
			cout<<sum;
	}
	
}
