#include<bits/stdc++.h>
using namespace std;
int b[5005];
int a[5005];
int e[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=5005;i++){
			a[i]=0;
			b[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];//Œª÷√ 
		}
		if(a[n]-a[1]<=d){
			cout<<0;
		}else{
			for(int i=1;i<=n;i++){
				e[i]=INT_MAX;
			} 
			e[1]=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						e[j]=min(e[j],e[i]+1);
					}
				}
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(e[i]+1==e[j]) b[i]++;
				}
			}
			int sum=0;
			for(int i=1;i<n;i++){
				if(b[i]==2){
					sum++;
				}
			}
			cout<<sum;
		} 
	} 
	return 0;
} 
