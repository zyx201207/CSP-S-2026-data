#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

// i believe this is very inefficient lol

struct Station
{
	int pass_time;
	std::vector<int> lines;
};

struct Line
{
	std::vector<int> stations_connected;
	std::vector<int> pass_time;
};

struct State
{
	int position;
	int64_t time;
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int test_point_id;
	std::cin >> test_point_id;
	
	int line_count,station_count,max_cross,queries;
	std::cin >> line_count >> station_count >> max_cross >> queries;
	
	Station stations[station_count];
	Line lines[line_count];
	for(int i = 0;i < station_count;i++)
	{
		std::cin >> stations[i].pass_time;
	}
	
	for(int i = 0;i < line_count;i++)
	{
		int stations_connected;
		std::cin >> stations_connected;
		for(int j = 0;j < stations_connected;j++)
		{
			int station_id,pass_time;
			std::cin >> station_id >> pass_time;
			
			lines[i].stations_connected.push_back(station_id - 1);
			lines[i].pass_time.push_back(pass_time);
			
			stations[station_id - 1].lines.push_back(i);
		}
	}
	
	
	for(int i = 0;i < queries;i++)
	{
		int from,to;
		std::cin >> from >> to;
		
		from--;
		to--;
		
		std::queue<State> q;
		bool sign[station_count] = {};
		State initial;
		initial.position = from;
		initial.time = stations[from].pass_time;
		sign[initial.position] = 1;
		q.push(initial);
		
		int64_t answer = INT64_MAX;
		while(!q.empty())
		{
			if(q.front().position == to)
			{
				//std::cout << "fans" << q.front().position << ' ' << q.front().time << ' ' << stations[q.front().position].pass_time << std::endl;
				answer = std::min(answer,q.front().time + stations[q.front().position].pass_time);
			}
				
			for(auto& available_lines : stations[q.front().position].lines)
			{
				for(int i=0;i < lines[available_lines].stations_connected.size();i++)
				{
					auto& station_id = lines[available_lines].stations_connected[i];
					if(sign[station_id] == false)
					{
						int index = 0;
						for(;index < lines[available_lines].stations_connected.size();index++)
						{
							if(q.front().position == lines[available_lines].stations_connected[index])
								break;
						}
						sign[station_id] = true;
					//	std::cout << q.front().position << ' ' <<station_id << ' ' << q.front().time << ' ' << ' ' << lines[available_lines].pass_time[i] << ' ' << lines[available_lines].pass_time[index] << ' ' << i << ' ' << available_lines << std::endl;
						q.push({station_id,q.front().time + lines[available_lines].pass_time[i] + lines[available_lines].pass_time[index]});						
					}
				}
			}
			q.pop();
		}
		
		std::cout << answer << std::endl;
	}
	return 0;
}
