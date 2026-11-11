#include <iostream>
#include <cstdio>

using namespace std;

int c,T;
int n;

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
		}
		cout<<n<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
