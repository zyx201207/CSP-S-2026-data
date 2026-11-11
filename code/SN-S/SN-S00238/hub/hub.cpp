#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x[500001],y[500001],sum;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum++;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x[i]>>y[i];
		}
		cout<<sum<<endl;
	}
	return 0; 
}
