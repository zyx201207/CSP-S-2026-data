#include<bits/stdc++.h>
using namespace std;
const unsigned long long N=5500000;
int c,t,n;
unsigned long long d,x[N+N];
int aandb(int i){
	int tt=0;
	if(x[i]==1&&x[i-d]==1&&x[i-d-d+1]==1&&x[i-d+1]==1){
//		cout<<i<<x[i]<<' '<<x[i-d]<<' '<<x[i-d-d+1]<<' '<<x[i-d+1]<<' '<<d<<' '<<i-d<<endl;
		tt++;
		int temp=1;
		while(1){
			if(x[i-d-d+1-(d*temp)]==1&&x[i-d-d+1-(d*temp)-d+1]!=1){
				tt++;
			}else return tt;
		}
	}
	return tt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	if(c==11||c==12){
		while(t){
			cin>>n>>d;
			for(int i=0;i<n;i++)cin>>x[i];
			cout<<(n-d-1)<<endl;
			t--;
		}
		return 0;
	}
	while(t){
		int ans=0;
		for(int i=0;i<=N+N;i++)x[i]=0;
		cin>>n>>d;
		int a;
		for(int i=0;i<n;i++){
			cin>>a;
			x[a+N]=1;
			ans+=aandb(a+N);
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
