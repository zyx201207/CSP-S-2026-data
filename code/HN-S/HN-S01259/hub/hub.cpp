#include<bits/stdc++.h>
using namespace std;
struct node{
	long long b,e;
}lv[5000500];
int  main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			cin>>lv[i].b>>lv[i].e;
		}
		if(k-n<=2){
			cout<<1<<endl;
			continue;
		}
	}
	fclose(stdin);
	return 0;
}
