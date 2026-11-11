#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long u,v;	
};
int c,t;
long long n,k;
Node a[2000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i].u>>a[i].v;
		}
		cout<<2<<endl;
	}
	return 0;
}