#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	int w[1005];
	
	
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	
	
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=w[i];
	}
	
	for(int i=1;i<=q;i++){
		cout<<sum<<endl;
	}
	
	return 0;
}
