#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
int b[1010000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c;
		cin>>b[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sum=max(sum,0&b[i]);
		}
		cout<<sum;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(sum,b[i]&b[j]);
			}
		}
		cout<<sum;
	}
	if(m==n){
		sum=b[1];
		for(int i=2;i<=n;i++){
			sum&=b[i];
		}
		cout<<sum;
	}
	return 0;
}
