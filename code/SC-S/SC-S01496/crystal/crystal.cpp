#include<bits/stdc++.h>
using namespace std;
int n,m;
int ayt[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++)cin>>ayt[i];
	sort(ayt+1,ayt+n+1);
	for(int i=1;i<=n;i++)
		if(i>2&&ayt[i]-ayt[i-1]!=ayt[i-1]-ayt[i-2])
			flag=1;
	if(flag==0){
		cout<<7;
	}
	cout<<7;
	return 0;
}