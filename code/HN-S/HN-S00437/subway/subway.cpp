#include<iostream>
using namespace std;
const int N=5e5+5;
const int M=1e5+5;
int station_time[N];
//每个地铁站入口时间 
struct Line{//每条线路经过的站及时间 
	int id,time;
}line[25][N];

struct Station{
	int id,place;
}station[505][25];
//每个站能去的线路与其位置 
int cnt[25];
int k[N];
long long mn=2147483647;
void search(int now,int ed,long long t,int path){
	if(line[now][1].id==0) return ;
	if(now==ed){
		t+=station_time[now];
		if(t<mn) mn=t;
		t-=station_time[now];
		return ;
	}
	for(int i=1;i<=cnt[now];i++){
		if(path==1){
			t+=station_time[now]; 
			int gotline=station[now][i].id;
			for(int j=1;j<=k[gotline];j++){
				if(j==station[now][i].place) continue;
				t+=line[gotline][station[now][i].place].time;
				t+=line[gotline][j].time;
				
				search(line[gotline][j].id,ed,t,path+1);
				t-=line[gotline][station[now][i].place].time;
				t-=line[gotline][j].time;
			} 
		}else{
			int gotline=station[now][i].id;
			for(int j=1;j<=k[gotline];j++){
				if(j==station[now][i].place) continue;
				t+=line[gotline][station[now][i].place].time;
				t+=line[gotline][j].time;
				cout<<endl<<line[gotline][j].id;
				
				search(line[gotline][j].id,ed,t,path+1);
				t-=line[gotline][station[now][i].place].time;
				t-=line[gotline][j].time;
		    }
    	}
    }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>station_time[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		
		for(int j=1;j<=k[i];j++){
			
			cin>>line[i][j].id>>line[i][j].time;
			station[line[i][j].id][++cnt[line[i][j].id]].id=i;
			station[line[i][j].id][cnt[line[i][j].id]].place=j;
		}
	}
	for(int i=1;i<=q;i++){
		int start,end;
		cin>>start>>end;
		mn=2147483647;
		search(start,end,0,1);
		cout<<mn<<endl;
	}
	return 0;
}

