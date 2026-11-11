#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int ans;
int diff;
int x[100005];
int mind=INT_MAX;	
int s[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			s[j]+=x[j];
			diff=s[j]-s[j-1];
			if(mind>=diff) mind=diff;
		}
		
	}
	if(d<mind) {
		cout<<"0"<<endl;
		return 0;
	}
	
}
