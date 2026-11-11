#include<bits/stdc++.h>
using namespace std;
int p[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,s=0;
	cin>>c>>t;
	while(t--){
		int n,d;
		int a[500005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		p[1]=1;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					p[j]+=p[i];
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(p[i]==2){
				s++;
				cout<<i<<endl;
			}
		}
		cout<<s<<endl;
		s=0;
	}
} 
