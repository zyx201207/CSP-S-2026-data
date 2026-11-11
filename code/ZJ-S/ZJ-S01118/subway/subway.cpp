#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[510];
long long int w[500010],floyd[510][510];
struct subway{
	int st;long long int tim;
};
vector<subway>sub[510];
struct station{
	int railway;long long int data;
};
vector<station>sta[500010];
long long int read(){
	char ch=getchar();long long int num=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		num=num*10+(ch-'0');
		ch=getchar();
	}
	return num;
}
void print(long long int num){
	if(num==0)return;
	print(num/10);
	char ch=char(num%10+'0');
	putchar(ch);
}
bool cmp(station aa,station bb){
	return aa.railway>bb.railway;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=0;j<k[i];j++){
			int val1=read();long long int val2=read();
			sub[i].push_back((subway){val1,val2});
			sta[val1].push_back((station){i,val2});
		}
	}//read data
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			floyd[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)sort(sta[i].begin(),sta[i].end(),cmp);
	for(int i=1;i<=n;i++){
		for(int i1=0;i1<k[i];i1++){
			int zhan1=sub[i][i1].st;
			int len=sta[zhan1].size();
			for(int i2=0;i2<len;i2++){
				int dt=sta[zhan1][i2].railway;
				if(dt<=i)break;
				long long int Dis=sub[i][i1].tim+sta[zhan1][i2].data;
				int d1=min(i,dt),d2=max(i,dt);
				floyd[d1][d2]=Dis;
				floyd[d2][d1]=Dis;
			}
		}
	}//make graph(subway is the point)+floyd[][]
	
	for(int t=1;t<=n;t++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int d1=min(i,t),d2=min(j,t);
				int d3=max(i,t),d4=max(j,t);
				floyd[i][j]=min(floyd[i][j],floyd[d1][d3]+floyd[d2][d4]);
			}
		}
	}//Floyd Time<O(n^3)
	
	while(q--){
		int x=read(),y=read();
		int len1=sta[x].size(),len2=sta[y].size();
		long long int ans=LLONG_MAX;
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				int d1=min(sta[x][i].railway,sta[y][j].railway);
				int d2=max(sta[x][i].railway,sta[y][j].railway);
				long long int now_dis=floyd[d1][d2]+sta[x][i].data+sta[y][j].data;
				ans=min(ans,now_dis);
			}
		}
		ans+=w[x]+w[y];
		print(ans);
		printf("\n");
	}//answer the questions
	
	return 0;
}