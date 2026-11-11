#include <bits\stdc++.h>
using namespace std;

struct p{
	int value;
	int cost;
};

bool cmp(p a,p b){
	return a.cost < b.cost;
}

const int INF = 1<<15;

int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	int ans = 0;
	int ans2 = 0;
	int n,m;
	fin >> n >> m;
	p p0;
	p0.value = 0;
	p0.cost = 0;
	bool flag = 0;
	int f=0;
	vector<p> a(n,p0);
	long long s = 0;
	for(int i=0;i<n;i++) {
		fin >> a[i].value;
		s += a[i].value;
		if(i==0) f=a[i].value;
		else if (a[i].value != f) flag=1;
	}
	if (flag == 0){
		fout << m%n << '\n';
		return 0;
	}
	double avg = s/1.0/n;
	int target = floor(avg);
	for(int i=0;i<n;i++) a[i].cost = (a[i].value > target ? INF : target-a[i].value);
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n;i++){
		if(m >= a[i].cost){
			m -= a[i].cost;
			a[i].value = target;
		}
	}
	for(int i=0;i<n;i++){
		if (a[i].value == target) ans++;
		else break;
	}
	//------
	target = ceil(avg);
	for(int i=0;i<n;i++) a[i].cost = (a[i].value > target ? INF : target-a[i].value);
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n;i++){
		if(m >= a[i].cost){
			m -= a[i].cost;
			a[i].value = target;
		}
	}
	for(int i=0;i<n;i++){
		if (a[i].value == target) ans2++;
		else break;
	}
	fout << max(ans,ans2) << '\n';
	return 0;
} 
