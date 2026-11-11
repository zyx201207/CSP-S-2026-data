#include <bits/stdc++.h>
using namespace std;
int main(void){
	ifstream fin("migrate.in", ios_base::in);
	ofstream fout("migrate.out", ios_base::out);
	int c, t;
	fin >> c >> t;
	while(t--){
		int n, d;
		fin >> n >> d;
		vector<int> pos(n, 0);
		for(int i=0;i<n;i++) fin >> pos[i];
		if(c == 11 || c == 12){
			int k = pos[1] - pos[0];
			int ans = 0;
			if(k * 2 < d && k * 3 > d)
				ans += n - 3;
			fout << ans << endl;
			continue;
		}
		int ans = 0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n&&pos[j]-pos[j-1]<d;j++){
				if(j<3+i) continue;
				if((j-i)%2==0){
					bool one = true;
					for(int k=i+2;k<j&&one;k+=2) if(pos[k] != pos[k-1] + d) one = false;
					if(one) continue;
				}	
				int cnt = 1;
				for(int k=i+1;k<j-1&&cnt<=2;k++)
					if(pos[k+2] - pos[k-1] > d && pos[k+1] - pos[k-1] <= d && pos[k+2] - pos[k] <= d) cnt++;
				if(cnt == 2) ans++;
			}
		}
		fout << ans << endl;
	}
	return 0;
}
