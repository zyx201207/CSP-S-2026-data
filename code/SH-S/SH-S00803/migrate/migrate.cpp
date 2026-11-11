#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
long long a[N];
int ans=2000010,ans2=0;
void f(int u,int v,int step){
	if(u==v){
		if(step==ans){
			ans2++;
		}else if(step<ans){
			ans2=1;
			ans=step;
		}
		return;
	}
	for(int i=u+1;i<=v;i++){
		if(a[i]-a[u]<=d){
			f(i,v,step+1);
		}
	}
	return;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			} 
			int fans=0;
			for(int i=3;i<=n;i++){
				if(d<(a[i]-a[1])&&d>(a[i-1]-a[1])){
					fans++;
				}
			}
			cout<<fans;
		}
		return 0;
	}
	while(t--){
		int fans=0;
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=2000010,ans2=0;
				f(i,j,0);
				if(ans2==2){
					fans++;
				} 
			}
		}
		cout<<fans<<endl;
	}
	return 0; 
} 
