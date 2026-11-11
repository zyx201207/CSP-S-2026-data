#include <bits/stdc++.h>
using namespace std;
struct subwayline{
	long long subwayline_to_subwayroom,goal_station;
};
vector <subwayline> subway_line[501];
vector <subwayline> subway_map[500064];
long long test_point,subway_line_number,subway_station_number,per_station_line,plan_number,line_station_number,flag=0,start_station,end_station,mintime=INT_MAX;
long long subwayroom_to_subwayexit[500064];
long long go_or_not[500064];
long long dfs(long long station,long long time,long long fa){
	if(fa!=0){
		for(int i=0;i<subway_map[station].size();i++){
			if(subway_map[station][i].goal_station==fa){
				time+=subway_map[station][i].subwayline_to_subwayroom;
			}
		}
	}
	if(station==end_station){
		mintime=min(mintime,time);
		return time;
	}
	go_or_not[station]=time;
	long long minn=INT_MAX;
	if(time>=mintime){
		return minn;
	}
	for(int i=0;i<subway_map[station].size();i++){
		if(go_or_not[subway_map[station][i].goal_station]>time+subway_map[station][i].subwayline_to_subwayroom){
			minn=min(minn,dfs(subway_map[station][i].goal_station,time+subway_map[station][i].subwayline_to_subwayroom,station));
		}
	}
	return minn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>test_point>>subway_line_number>>subway_station_number>>per_station_line>>plan_number;
	for(int i=1;i<=subway_station_number;i++){
		cin>>subwayroom_to_subwayexit[i];
	}
	subwayline x;
	for(int i=0;i<subway_line_number;i++){
		cin>>line_station_number;
		for(int j=0;j<line_station_number;j++){
			cin>>x.goal_station>>x.subwayline_to_subwayroom;
			subway_line[i].push_back(x);
		}
	}
	for(int i=0;i<subway_line_number;i++){
		for(int j=0;j<=subway_line[i].size();j++){
			for(int k=j+1;k<subway_line[i].size();k++){
				x.subwayline_to_subwayroom=subway_line[i][k].subwayline_to_subwayroom;
				x.goal_station=subway_line[i][k].goal_station;
				flag=0;
				for(int l=0;l<subway_map[subway_line[i][j].goal_station].size();l++){
					if(subway_map[subway_line[i][j].goal_station][l].goal_station==x.goal_station){
						flag=1;
						if(subway_map[subway_line[i][j].goal_station][l].subwayline_to_subwayroom>x.subwayline_to_subwayroom){
							subway_map[subway_line[i][j].goal_station][l].subwayline_to_subwayroom=x.subwayline_to_subwayroom;
						}
					}
				}
				if(flag){
					for(int l=0;l<subway_map[subway_line[i][k].goal_station].size();l++){
						if(subway_map[subway_line[i][k].goal_station][l].goal_station==subway_line[i][j].goal_station){
							flag=1;
							if(subway_map[subway_line[i][k].goal_station][l].subwayline_to_subwayroom>subway_line[i][j].subwayline_to_subwayroom){
								subway_map[subway_line[i][k].goal_station][l].subwayline_to_subwayroom=subway_line[i][j].subwayline_to_subwayroom;
							}
						}
					}
				}
				if(!flag){
					subway_map[subway_line[i][j].goal_station].push_back(x);
					x.goal_station=subway_line[i][j].goal_station;
					x.subwayline_to_subwayroom=subway_line[i][j].subwayline_to_subwayroom;
					subway_map[subway_line[i][k].goal_station].push_back(x);
				}
			}
		}
	}
	while(plan_number--){
		for(int i=0;i<=subway_station_number;i++){
			go_or_not[i]=INT_MAX;
		}
		mintime=INT_MAX;
		cin>>start_station>>end_station;
		cout<<subwayroom_to_subwayexit[start_station]+subwayroom_to_subwayexit[end_station]+dfs(start_station,0,0)<<endl;
	}
	return 0;
}