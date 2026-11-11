#include<bits/stdc++.h>
using namespace std;

int a[5010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m==1){
		for(int i=1;i<=n;i++) cout<<n<<" ";
		cout<<"\n";
		return 0;
	}
	if(m==2){
		int u=a[n],cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=u) cnt++;
		}
		if(a[n]==1) cout<<n<<" "<<cnt<<"\n";
		else cout<<cnt<<" "<<n<<"\n";
	}
	
	return 0;
}
