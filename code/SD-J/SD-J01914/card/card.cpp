#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,ans=0,m;
	cin>>n>>m;
	bool ax=true,ay=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])ay=false;
		if(a[i]>a[i-1])ay=false;
		else ax=false;
	}
	if(ax){
		for(int i=1;i<=m;i++){
			if(i<n)cout<<i;
			else cout<<n;
			cout<<" ";
		} 
	}if(ay||m==1){
		cout<<n<<" "; 
	}
	return 0;
}
