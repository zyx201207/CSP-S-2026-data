#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	int cha=a[2]-a[1];
	for(int i=sqrt((m/cha)*2);1;i--){
		if(i*(i-1)*cha<=m*2){
			cout<<i;
			return 0;
		}
	}
	return 0;
}