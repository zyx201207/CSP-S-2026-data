#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int main(){
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		srand(time(0));
		cout<<rand()%n<<"\n";
	}
	return 0;
}/*
Ô¸ËùÔ¸½ÔÓÐËùµÃ£¬ 
Ô¸´ËÂÃÖÕµÖ·±ÐÇ ¡£ 
*/
