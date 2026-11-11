#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int x[N];
int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	
	int sum,cnt;
	while(t--){
		int n,d;
		cin>>n>>d; 
		sum=0,cnt=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
			sum+=x[i];
			cnt++;
		}
		cout<<sum/cnt<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
