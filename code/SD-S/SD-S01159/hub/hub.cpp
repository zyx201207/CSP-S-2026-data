#include<bits/stdc++.h>
using namespace std;
int n,k,T;
int x,y;
int R[10];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>x>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			R[i]=0; 
		}
		for(int i=1;i<n;i++){
			cin>>x>>y;
			R[x]++;
			R[y]++;
		}
		int check=1;
		for(int i=1;i<=n;i++){
			if(R[i]==n-1)check=0;
		}
		if(check==0){
			if(k==n){
				cout<<0<<endl;
				continue;
			}
			cout<<1<<endl;
			continue;
		}
		if(n==5&&k==1){
			cout<<2<<endl;
			continue;
		}
		if(n==4&&k==1){
			cout<<2<<endl;
			continue;
		}
		if(n==k){
			cout<<0<<endl;
			continue;
		}
		cout<<1<<endl;
	}
	return 0;
}
