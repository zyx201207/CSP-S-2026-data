#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ei[1000000];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	
	cin>>c>>t;
	int e[1000000];
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>e[i];
}
		int sum=0;
		
			for(int i=1;i<=n;i++){
			if(e[i]+d+1<=n&&e[i]+d+1==e[i+d+1]){sum++;}

		
	}
		cout<<sum<<endl;
	}
	
	
	return 0;
} 
