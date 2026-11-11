#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=505;
const int M=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll in(){
	char c=getchar();
	ll num=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+(c-'0');
		c=getchar();
	}
	return num*f;
}

void out(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10) putchar(x+'0');
	else{
		out(x/10);
		putchar((x%10)+'0');
	}
}

ll c,n,m,d,q;
ll w[M],dis[N][N];

struct QAQ{
	ll id,ctim;
};

struct subway{
	int k;
	vector<QAQ> a;//线路可到达的站点a，以及a站台到a大厅的时间 
}awa[N];

struct station{
	vector<QAQ> asub;//asub:the id of the subway that past the station.ctim:the tine it cost from the dining to the asub's realway_station 
}st[M];

queue<int> qu;
bool vis[N];

int main(){
	memset(dis,0x3f,sizeof(dis));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in();n=in();m=in();d=in();q=in();
	for(int i=1;i<=m;i++) w[i]=in();
	for(int i=1;i<=n;i++){//read the date and prepare the dates of stations
		awa[i].k=in();
		for(int j=1;j<=awa[i].k;j++){
			QAQ input,ins;
			input.id=in();
			input.ctim=in();
			awa[i].a.push_back(input);
			ins.id=i;ins.ctim=input.ctim;
			st[input.id].asub.push_back(ins);
		}
		qu.push(i);vis[i]=1;
		dis[i][i]=0;
	}
//	for(int i=1;i<=m;i++){//check the date of station
//		cout<<i<<":"<<endl;
//		for(auto j:st[i].asub){
//			cout<<j.id<<" "<<j.ctim<<endl;
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)//地铁线编号 
		for(auto fr: awa[i].a)//pass stations 
			for(auto to:st[fr.id].asub){//could arrive 
				dis[i][to.id]=min(dis[i][to.id],fr.ctim+to.ctim);
//				cout<<i<<" "<<to.id<<endl;
			}
//	for(int i=1;i<=n;i++){//charck 初始dis
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(!qu.empty()){
		int now=qu.front();
		qu.pop();vis[now]=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(dis[i][j]>dis[i][now]+dis[now][j]){
				dis[i][j]=dis[i][now]+dis[now][j];
				if(n<=50&&vis[j]==0){
					vis[j]=1;
					qu.push(j);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){//charck dis
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		ll u=in(),v=in(),ans=INF;
		for(auto i:st[u].asub){
			for(auto j:st[v].asub){
//				cout<<i.id<<" "<<j.id<<endl;
				ans=min(dis[i.id][j.id]+i.ctim+j.ctim,ans);
			}
		}
//		cout<<ans<<endl;
		out(ans+w[u]+w[v]);
		printf("\n");
	}
	
	return 0;
}

//-g3
//第一次场切T2（通过所有大样例 



 
