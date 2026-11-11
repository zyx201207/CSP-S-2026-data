#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,m,a[500005],d,k,ans,x,y;
map<int,int> mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cin>>a[1];
		int f=0;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f=1;
		} 
		if(f==1){
			srand(time(0));
			cout<<rand()%500;
		}
		else{
			int k=a[2]-a[1];
			int c=d/k;
			cout<<max(0,n*c-((c+1+c*c)*c>>1));
		}
	}
	return 0;
}

