#include<bits/stdc++.h>
using namespace std;
struct line{
	vector<long> sta;
	vector<long> sttim;
};
struct station{
	long out_sta;
	vector<long> lin;
	vector<long> sttm;
};

station sta[20010];
line li[510];
vector<bool> vistat(20010,0);
long dfs( long x , long y , long ti ){
	if( x == y ){
		return ti;
	}
	long mi = -1;
	for( long i = 0 ; i < sta[x].lin.size() ; i++ ){
		long tmp = ti + sta[x].sttm[i] , tmline = sta[x].lin[i];
		for( long j = 0 ; j < li[tmline].sta.size() ; j++ ){
			if( vistat[x] == 0 ){
				long t = dfs( li[tmline].sta[j] , y , tmp + li[tmline].sttim[j] );
				if( t != -1 ){
					mi = t ;
				}
			}
		}
	}
	return mi;
}
int main(){
	freopen( "subway.in" , "r" , stdin );
	freopen( "subway.out" , "w" , stdout );
	long c , n , m , d , q ;
	cin >> c >> n >> m >> d >> q;
	for( long i = 0 ; i < m ; i++ ){
		cin >> sta[i].out_sta;
	}
	for( long i = 0 ; i < n ; i++ ){
		long k;
		cin >> k;
		for( long j = 0 ; j < k ; j++ ){
			long t , a;
			cin >> a >> t;
			li[i].sta.push_back(a);
			li[i].sttim.push_back(t);
			sta[a].sttm.push_back(t);
			sta[a].lin.push_back(i);
		}
	}
//	for( long i = 0 ; i < n ; i++ ){
//		cout << li[i].sta.size() << ' ';
//		for( long j = 0 ; j < li[i].sta.size() ; j++ ){
//			cout << li[i].sta[j] << ' ';
//			cout << li[i].sttim[j] << ' ';
//		}
//	}
	for( long i = 0 ; i < q ; i++ ){
		long x , y;
		cin >> x >> y;
		for( long j = 0 ; j < m ; j++ ){
			vistat[j] = 0;
		}
		cout << dfs( x , y , 0 ) + sta[x - 1].out_sta + sta[y - 1].out_sta << endl;
	}
	fclose( stdin );
	fclose( stdout );
	return 0;
}
