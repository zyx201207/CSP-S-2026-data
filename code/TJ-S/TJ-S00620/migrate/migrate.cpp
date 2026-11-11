#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		int n,d,a,b;
		cin>>n>>d>>a>>b;
		cout<<(b-a)*n<<endl;
		t--;
	}
	return 0;
}
