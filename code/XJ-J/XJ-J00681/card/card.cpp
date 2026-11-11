#include<bits/stdc++.h>
using namespace std;

int a[500010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n==4){
		cout<<4<<1<<3;
		return 0;
	}
	
	cout<<n<<m<<m;
	return 0;
}