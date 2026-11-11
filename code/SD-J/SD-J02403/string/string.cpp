#include<bits/stdc++.h>
using namespace std;
string S;
int main()
{
	cin.tie(0);
		cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	int a;
	char c;
	long long L=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		L+=a;
		cin>>c;
		for(int j=1;j<=a;j++)
		S+=c;
	}
	long long cnt=0;
	for(int i=0;i<=L/2;i++)
	if(S[i]!=S[L-i-1])cnt++;
	cout<<cnt;
	return 0;
 } 
 
