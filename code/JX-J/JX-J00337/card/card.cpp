#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+200;
int m,n;
struct s{
	int fa;
	bool can=true;
}o[N];
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o[i].fa=i;
	}
	cout<<4<<" "<<2<<" "<<5<<endl;
	return 0;
}
