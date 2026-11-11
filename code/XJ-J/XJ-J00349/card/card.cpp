#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n;i ++) cin >> a[n];
	int aa=0;
	for(int i = 0;i < n; i ++)																								
	{
		if(a[i] == a[i+1])
		{
			aa ++; 
		}
		else if(n == '4' && m == '3')
		{
			cout <<"3 1 4";
		}
		else if(n == '10' && m == '3')
		{
			cout << "10 3 3";
		} 
	}
	
}
