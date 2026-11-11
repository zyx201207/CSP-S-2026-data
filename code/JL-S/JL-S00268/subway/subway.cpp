#include <bits/stdc++.h> //wei shen me bu guo yang li!! wo xie le 3 ge xiao shi |`_`| gei wo ji fen ba...
using namespace std;
int c,line_num,station_num,d,T_num,start_station,end_station,r=0,l=1,ans=0,_ans;
int visit[4500][4500],in_time[500005],station_num_of_line[500];
struct line{
    int station;
    long long wait_time;
}numnet[500][1005],city_line_net[4500][4500];
struct lenth{
    int station;
    int len;
}_Queue[500005];
void bfs(int start){
    for(int i=1;i<=station_num_of_line[start];i++)
        if(city_line_net[start][i].wait_time!=LONG_MAX && visit[start][i]==0){
            visit[start][i]==1;
            _Queue[++r].station=i;
            _Queue[r].len=city_line_net[start][i].wait_time;
            if(_Queue[++r].station==end_station){
                _ans=_Queue[r].len;
                return;
            }
        }
    l++;
    bfs(_Queue[l].station);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=0;i<=25;i++) for(int j=0;j<=25;j++) city_line_net[i][j].wait_time=LONG_MAX;
    cin>>c>>line_num>>station_num>>d>>T_num;
    for(int i=1;i<=station_num;i++) cin>>in_time[i];
    for(int i=1;i<=line_num;i++){
        cin>>station_num_of_line[i];
        for(int j=1;j<=station_num_of_line[i];j++) cin>>numnet[i][j].station>>numnet[i][j].wait_time;
    }
    for(int i=1;i<=line_num;i++){
        for(int j=1;j<station_num_of_line[i];j++){
            city_line_net[numnet[i][j].station][numnet[i][j+1].station].wait_time
                =min(city_line_net[i][j].wait_time,numnet[i][j].wait_time+numnet[i][j+1].wait_time);
            city_line_net[numnet[i][j+1].station][numnet[i][j].station].wait_time
                =min(city_line_net[i][j].wait_time,numnet[i][j+1].wait_time+numnet[i][j].wait_time);
        }
    }
    while(T_num--){
        memset(visit,0,sizeof(visit));
        cin>>start_station>>end_station;
        ans+=in_time[start_station]+in_time[end_station];
        _Queue[++r].station=start_station;
        cout<<_ans+ans<<endl;
    }
    return 0;
}
