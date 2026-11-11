#include <bits\stdc++.h>
using namespace std;

int c;

int solve(int n,int max_dist,vector<int> islands){
	if(c==11 || c==12){
		int first = islands[0]
		int last = islands[n-1]
		int d = islands[1]-first;
		max_dist -= max_dist%d;
		int cnt = 0;
		for(int i=d;first+i<=last;i+=d){
			for(int j=1;i<d;j++){
				dist=i+j;
				cnt += n-(last-first)%dist;
			}
		}
		return cnt;
	}
	return 0;
}

int main(){
	ifstream fin("migrate.in");
	ofstream fout("migrate.out");
	int t;
	fin >> c >> t;
	while(t--){
		int n,d;
		fin >> n >> d;
		vector<int> a(n);
		for(int i=0;i<n;i++) fin >> a[i];
		fout << solve(n,d,a) << '\n';
	}
	return 0;
} 
