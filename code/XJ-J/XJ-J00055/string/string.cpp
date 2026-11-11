#include<bits/stdc++.h>;
using namespace std;
long long n,sum=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    for(int i=0;i<=n;i++)
    {
    	cin>>s[i];
    	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i]!=s[j])
			{
				sum+=1;
			}
			else
			{
				cout<<"0";
			}
		}
	}
	cout<<sum;
	return 0;
}
