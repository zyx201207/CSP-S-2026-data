//crystal
#include<bits/stdc++.h>
using namespace std;
int l,c,n,m,s;
int a[2000005],b[2000005];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>l>>c;
	for(int i=0;i<c;i++)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]; 
			b[i]=b[i-1]+a[i]-a[i-1];
		}
		for(int i=0;i<n;i++)
		{
			if(b[i]%4==0)
			s++;
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
