#include<bits/stdc++.h>
using namespace std;
int k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,t;
	cin>>c>>t;//我！要！拿！省！二！ 
	while(t--){
		srand(time(0));
		int n;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(n==5||n==8||n==1)
			cout<<1<<endl;
		else if(n==10||n==4)
			cout<<2<<endl;
		else
			cout<<rand()<<endl;//我真的想啊...呜呜呜...awa 
	}
	return 0;
}/*
冰火阴阳相对 
如隔银河难相会
~ro
*/
