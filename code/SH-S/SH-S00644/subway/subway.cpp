#include<bits/stdc++.h>
using namespace std;

long long minn(long long a[60][310], long long t[60][310], long long trans[310], long long idx){
	long long curr = 10000000000;
	long long minst = 0;
	for(int i = 0; i < 310; i++){
		if(t[idx][i] < curr && trans[a[idx][i]] > 1){
			curr = t[idx][i];
			minst = a[idx][i];
		}
	}
	return minst;
}

vector<long long> transfer(long long a[60][310], long long pos){
	vector<long long> tr;
	for(int i = 0; i < 60; i++){
		for(int j = 0; j < 310; j++){
			if(a[i][j] == pos)	tr.push_back(i);
		}
	}
	return tr;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
for(int z = 0; z <= c; z++){
	//prepare
	long long w[m+10];
	for(int i = 0; i < m; i++)	cin >> w[i];
	long long a[60][310], t[60][310];
	long long trans[310] = {};
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> a[i][j] >> t[i][j];
			trans[a[i][j]]++;
			//how many lines exist for every station
		}
	}
	long long r[q][2];
	for(int i = 0; i < q; i++)	
		cin >> r[i][0] >> r[i][1];
	
	
		
	//calculate
for(int zz = 0; zz < q; zz++){
	long long st = r[zz][0]; //starting station idx
	long long ter = r[zz][1];//terminal station idx
	long long linest = 0, stast = 0, lineter = 0, stater = 0;
	//starting line, station & terminal line, station
		
	//if st & ter in the same line
	bool flag1 = false, flag2 = false, flag3 = false;
	for(int i = 0; i < 60; i++){
		for(int j = 0; j < 310; j++){
			if(a[i][j] == st){
				flag1 = true;
				linest = i;
				stast = j;	
			}
			if(a[i][j] == ter)	{
				flag2 = true;
				lineter = i;
				stater = j;
			}
		}
		if(flag1 && flag2){
			cout << w[st] + w[ter] + t[linest][stast] + t[lineter][stater] << endl;
			flag3 = true;
			break;
		}
	}
	if(flag3)	continue;
	
	//regular calculation
	long long sum = 0;
	bool flag = false;
	int stt = st;
	while(true){
		long long mint = minn(a, t, trans, stt);
		vector<long long> ex = transfer(a, mint);
		sum += mint;
		for(int i = 0; i < ex.size(); i++){
			if(ex[i] == lineter){
				flag = true;
				break;
			}
		}
		if(flag)	break;
		stt = ex[0];
	}
	cout << w[st] + w[ter] + sum << endl;
}
	
	
} 
	
	
	return 0;
} 
