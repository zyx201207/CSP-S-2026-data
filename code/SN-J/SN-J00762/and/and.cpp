#include <bits/stdc++.h>
using namespace std;
int a[100005],n,m,s,d;
int b=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;

	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=m;j++)
			for(int i=1;i<=n;i++)
				if(a[i]%2!=0)
					b=a[i]-a[i]%2;
	cout<<b;
	
	
		
	
	
	
	
	
	return 0;
}
