#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,line_num,station_num,line_passed_max,plan;
	cin>>c>>line_num>>station_num>>line_passed_max>>plan;
	int start[10],end[10],enter_to_hall[30],station_pass_sum[30],station_pass[30],hall_to_stage[30];
	for(int i=1;i<=30;i++)
	{
		cin>>enter_to_hall[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>station_pass_sum[i];
		for(int j=1;j<=station_pass_sum[i];j++)
		{
			cin>>station_pass[j]>>hall_to_stage[j];
		}
	}
	for(int i=1;i<=plan;i++)
	{
		cin>>start[i]>>end[i];
	}
	for(int i=1;i<=plan;i++)
	{
		cout<<enter_to_hall[start[i]]+hall_to_stage[start[i]]+hall_to_stage[end[i]]+enter_to_hall[end[i]]<<endl;
	}
	return 0;
}