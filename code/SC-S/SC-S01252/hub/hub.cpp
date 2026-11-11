#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,T;
	cin>>c>>T;
	for(int rnd=1;rnd<=T;rnd++){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
		}
		
		int m=n/2;
		cout<<(m+1-(m-k)/2-k)<<endl;
	}
	
	
	
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}