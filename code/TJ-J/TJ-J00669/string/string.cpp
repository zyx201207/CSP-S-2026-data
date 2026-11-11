#include<bits/stdc++.h>
using namespace std;

int main£¨£©
£û
	freopen£¨string.in,"r",in£©;
	freopen£¨string.out,"w",out£©;
	int n;
	cin>>n;
	int cnt=0;
	int l;
	cin>>l;
	string num[1000000];
	for(int i=1£»i<=n;i++)
	£û
		cin>>num[i]; 
	£ý 
	reserve
	for£¨int i=1;i<=n;i++£©
	£û
		if(n[i-1]==n[i])
		{
			cnt++;
		}
	£ý 
	cout<<cnt;
	return 0; 
£ý 
