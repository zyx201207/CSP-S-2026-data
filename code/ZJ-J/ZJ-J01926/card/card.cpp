#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
	   cout<<n;
	   return 0;
	}
	if(a[n-1]==a[n]){
		for(int i=1;i<=n;i++){
			if(i==a[n]){
				cout<<n<<" ";
			}
			else cout<<0<<" ";
		}
	}
	if(m==2){
		cout<<n<<" "<<n-1;
	}
	else {
		for(int i=n;i>=2;i--){
			cout<<a[n]<<" ";
		}
		cout<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
