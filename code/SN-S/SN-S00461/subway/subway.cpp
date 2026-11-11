//SN-S00461 高子修 西安市第六中学 
/*
 *thanks!give me case id!!!
 * i can get A or B and other
 * awa 
 */
//SN-S00461 高子修 西安市第六中学 

#include<bits/stdc++.h>
using namespace std;
int w[505],a[505],t[500005];
int c,n,m,d,q,k;
int endd,start;
bool vis[505];
vector<int> map[505];
struct node{
	int time,line,line2;
};
node id[505];

int a111=0x3f3f3f3f;
void solve2021(){
	//n==2 only two line
	if((id[start].line==id[endd].line)||(id[start].line2==id[endd].line)||(id[start].line==id[endd].line2)||(id[start].line2==id[endd].line2))cout<<w[start]+w[endd]+id[start].time+id[endd].time;
	else cout<<w[start]+w[endd]+a111;
	
}

int main(){
	 freopen("subway.in","r",stdin);
	 freopen("subway.out","w",stdout);
	
	cin>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int j=1;j<=n;j++){
		cin>>k;
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			if(id[x].time!=0)a111=min(id[x].time+y,a111);
			if(id[x].line!=0)id[x].line2=i;
			else id[x].line=i;
			id[x].time+=y;
		}
	}
	while(q--){
		cin>>start>>endd;
		if(c>=20&&c<=21)solve2021();
		//~ solve();
//		if(c>=7&&c<=11)solveA()
	}
	return 0;
}
