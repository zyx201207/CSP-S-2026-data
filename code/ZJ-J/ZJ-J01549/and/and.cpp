#include<bits/stdc++.h>
using namespace std;
int a[200010],b[10];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(m<=b[4])
		cout<<4;
	else if(m<=b[3])
		cout<<3;
	else if(m<=b[2]||m<=b[3]+b[2])
		cout<<2;
	else if(m<=b[1]||m<=b[3]+b[1])
		cout<<1;
	return 0;
}
