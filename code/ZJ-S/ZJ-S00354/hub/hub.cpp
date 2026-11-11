#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a;
		for(int i = 0;i<n;i++){
			cin>>a>>a;
		}
		int l = (n+1)/2;
		if(l%2){
			l/=2;
			l+=1;
			k/=2;
			cout<<(l-k+2)/2<<'\n';
		}
		else{
			l/=2;
			l+=1;
			k+=1;
			k/=2;
			cout<<(l-k+2)/2<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
