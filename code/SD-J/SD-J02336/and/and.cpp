#include<bits/stdc++.h>
using namespace std;
int a[2026][2026],x[2026];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long tl=0;
	cin>>n>>m;
	int sk=n;
	for(int i=1;i<=n;i++){
			cin>>x[i];
			tl+=x[i];
		}
		if(m==1){
			int k=0;
			for(int i=1;i<=n;i++){
				k=max(k,x[i]);
			}
			cout<<k;
		}
		else if(m==n){
			int k=1;
			for(int i=1;i<=n;i++){
				k=k&x[i];
			}
			cout<<k;
		}
		else if(m==2){
			int k=1;
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
				k=max(k,x[i]&x[j]);
			}
			}
			cout<<k;
		}
		else if(tl<4) cout<<3;
		else{
			while(1){
				if(sk==2){
					cout<<1;
					return 0;
				}
				else if(sk%2==0) sk=sk/2;
				else break;
			}
			int k=1e9;
			for(int i=1;i<=n;i++){
				k=min(k,x[i]);
			}
			cout<<k;
		}
	return 0;
}
