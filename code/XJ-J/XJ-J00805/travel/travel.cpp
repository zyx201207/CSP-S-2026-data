#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	cin>>n;
	int a=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==x){
			a++;	
		}
	}
	cout<<a;
	return 0;
}