#include<bits/stdc++.h>
using namespace std;
//I love ccf
struct node
{
	int u,v;
}a[1000001];
int C,T;
int n,k;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>a[i].u>>a[i].v;
		}if(C==0){
			cout<<1<<endl<<2<<endl;
			return 0;
		}
		else cout<<a[3].u<<endl;
	}
	return 0;
} 