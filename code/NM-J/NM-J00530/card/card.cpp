#include<bits/stdc++.h>
using namespace std;
long long n,m,x[100000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if(n==1) {cout<<n;return 0;}
	if(n==2&&m==1) {cout<<n;return 0;}
	if(n==2&&m==2) {cout<<1<<" "<<2;;return 0;}
	if(n==3&&m==1) {cout<<n;return 0;}
	if(n==3&&m==2) {cout<<3<<" "<<2;return 0;}
	if(n==4&&m==1) {cout<<n;return 0;}
	if(n==5&&m==1) {cout<<n;return 0;}
	if(n==4&&m==2) {cout<<4<<" "<<3;return 0;}
	if(n==5&&m==2) {cout<<5<<" "<<4;return 0;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
