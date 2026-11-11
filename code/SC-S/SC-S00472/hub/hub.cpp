#include<bits/stdc++.h>
using namespace std;
int a[10001][10001];
int b[100001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int e,f;
			cin>>e>>f;
			a[e][f]=1;
		}
		if(n%2==0){
			b[j]=2;
		}else{
			b[j]=1;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<b[i]<<endl;
	}
	return 0;
}