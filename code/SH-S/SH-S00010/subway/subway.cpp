//subway
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct point{
	int num;
	bool type; //0=station, 1=subway
};
struct side{
	point* from;
	point* to;
	int time;
};



int main(){
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >>q;
	vector<int> w(m+5);
	vector<int> k(n+5);
	vector<side> s;
	vector<point> p;
	vector<point> p_line; 
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	int atmp, ttmp;
	for (int i=1;i<=n;i++){
		cin >> k[i];
		point tmp;
		for (int j=1;j<=k[i];j++){
			cin >> atmp >> ttmp;
			
		}
	}
	
}

