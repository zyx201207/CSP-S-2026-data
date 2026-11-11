#include <bits/stdc++.h>
using namespace std; 
int num[10];
char str[10];
int n;
int h;
string sd;
int r;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		cin>>str[i];
	}
	for(int i=0;i<n;i++) 
	{
	r+=num[i];	
	}
	for(int i=0;i<(n-1);i++)
	{
		if(str[i]==str[i+1])h++;
	}
	if(h==n-1)cout<<0;
	else cout<<r/2; 
	//cout<<h<<" "<<n<<" "<<r;
	
	return 0;
}
