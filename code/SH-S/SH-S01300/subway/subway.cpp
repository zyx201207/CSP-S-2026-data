#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[510],a[510][20010],t[510][20010],x,y;
int dis[510][510];//Õ¾Ìü
//bool able[510][20010]; 
int dis16[310][310][50];

int sv16(){
	queue<int>q;
	q.push(x);
	while(q.size()){
		int t=q.front();
		q.pop();
		
	}
	return 0;
}




int main(){
	//freopen()
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			//able[a[i][j]][i]=1;
		}
	}
	while(q--){
		cin>>x>>y;
		if(c<=6) cout<<sv16();
		cout<<0<<endl;
	}
	
	
	//fclose()
	fclose(stdin);
	fclose(stdout);
	//Entrance to the Chaos
	return 0;
}
