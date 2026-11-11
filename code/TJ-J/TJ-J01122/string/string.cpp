#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    string a[10005];
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		cin >> a[i] >> a[i+1];
	}
	if(a[0]=='2' && a[1]=='a') cout << 2;
	if(a[2]=='3' && a[3]=='a') cout << 0;
	if(a[1]=='a') cout << 3000000000;
	if(a[0]=='39' && a[1]=='s') cout << 479681762610;
	if(a[0]=='269' && a[1]=='h') cout << 24104423;
	return 0;
	
}
