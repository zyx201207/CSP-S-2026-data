#include<bits/stdc++.h>
using namespace std;
int n;
//int a[10005],ans=0,num=0;
//string b;
int a,num,ans1,ans2;
char c;
string b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b;
		num+=a[i];
		
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<num/2;j++)
		{
			if(string[0]==string[n-j-1])
			{
				if(a[i]==a[n-j-1]){
					
				}
				else{
					if(a[i]a[n-j-1])
				}
			}
		}
	}*/
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		num+=a;
		for(int j=0;j<a;j++)
		{
			b+=c;
		}
	}
	for(int i=0;i<num/2;i++)
	{
		if(b[i]==b[num-i-1])
		{
			
		}
		else{
			ans1++;
		}
	}
	cout<<ans1;
	return 0;
}
