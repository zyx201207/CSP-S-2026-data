#include <bits/stdc++.h>
using namespace std ;
int main (  ) { 
	int c,n,m,d,q,w[1000],k[1000],a[1000][1000],t[1000][1000],x[1000],y[1000] ;
/* 
c 测试点编号 n 地铁线路数 m 地铁站数 
d 每个地铁站最多被几条线路经过 q 出行计划数
w 从每个地铁站的地铁口走到站厅需要的时间
k 第 i 条线路经过的地铁站数
a 第 i 条线路经过的第 j 个地铁站
t 从该地铁站的站厅走到第 i 条线路的站台需要的时间
x,y 第 r 个出行计划的起点和终点所在的地铁站编号。
*/	cin >> c >> n >> m >> d >> q ;
	for ( int i=0 ; i<m ; i++ ) { 
		cin >> w[i] ;
	} 
	for ( int i=0 ; i<n ; i++ ) { 
		cin >> k[i] ;
		for ( int j=0 ; j<k[i] ; j++ ) { 
			cin >> a[i][j] >> t[i][j] ;
		} 
	} 
	for ( int i=0 ; i<q ; i++ ) { 
		cin >> x[i] >> y[i] ;
	} 
	
	return 0 ;
} 
/*
【样例 1 输入】
2 5 20 2
4 1 9 2 5
3   1-5 2-7 4-6
3   2-3 3-4 5-7
1->3
1->2
【样例 1 输出】
32
17
*/
