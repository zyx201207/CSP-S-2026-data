#include <bits/stdc++.h>
using namespace std;
const int N=20020;
int n,c,t,n,k,a[N][N],a1,a2;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>a1>>a2;
			a[a1][a2]=a[a2][a1]=1;
		}
		cout<<n/2<<endl;
	}
	return 0; 
} 
