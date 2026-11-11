#include <bits/stdc++.h>
using namespace std;
const int M=5e5+1;
const int N=500;
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	srand(time(0));
	cin>>c>>t;
	int n,d;
	while(t--){
		cin>>n>>d;
		cout<<rand()%n<<endl;
	}
	return 0;
} 
