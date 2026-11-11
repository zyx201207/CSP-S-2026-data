#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000005];
string s;
int main()
{
	freopen("string.in" ,"r" ,stdin);
	freopen("string.out" ,"w",stdout);
	cin >>n;
	for(int i = 0 ;i < n ; i++)
	{
		cin >> a[i];
		cin >> s;
	}
	

	string s1;
	for(int i = n-1; i>=0 ;i--){
		s1[i] = s[n-i];
	}
	int cnt =0;
	for(int i=0 ; i< n ;i++){
		if(s[i] != s1[i])
			cnt+=a[i];
	}
	cout << cnt;
	return 0;
}
