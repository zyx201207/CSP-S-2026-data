#include<bits/stdc++.h>
using namespace std;
int a[100110];
char k[100110].kk[100110];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	   cin>>a[i]>>k[i];
	if(n==1) {cout<<0;return 0;}
	for(int i=1;i<=n;i++)
	   kk[k[i]]++;
	bool f;
	for(int i=1;i<=n;i++)
	    if(kk[i]==n) f=true;
	            else continue;
    fclose(stdin);
	fclose(stdout); 
	return 0; 
} 
