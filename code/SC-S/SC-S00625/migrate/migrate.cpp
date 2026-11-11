#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int C,T;
int n,d;
int x[N];
int mid[N]={0};
int main(){
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(x[1]-x[2]>d){cout<<0<<endl;continue;}
		int tot=0;
		for(int i=2;i<=n;i++)if(x[i]-x[i-1]>d)mid[tot]=i;
		int ans=0,u=1;
		for(int i=1;i<=n;i++){
			u=1;
			for(int j=mid[i]+1;j<=mid[i];j++)u*=j/2;
			ans+=u;
		}
		cout<<(ans&2)<<endl;
	}
	return 0;
}

