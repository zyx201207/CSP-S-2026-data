#include <bits/stdc++.h>
using namespace std;
int n,m,tet,cnt,cc,ans;
vector<int> twt[31],owo,quq;
void tot(int tet,int i){
	for(int j = 0;j<=30 and tet;j++){
		if(tet % 2) twt[j].push_back(i);
		tet >>= 1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> tet;
		tot(tet,i);
	}
	for(int i = 30;i>=0;i--){
		if(twt[i].size()>=m){
			if(owo.size() == 0){
				owo = twt[i];
				ans += pow(2,i);
			}
			else{
				cnt = 0;
				cc = 0;
				quq = {};
				for(int j = 0;j<twt[i].size();j++){
					for(;cc<owo.size() and owo[cc] <= twt[i][j];cc++){
						if(owo[cc] == twt[i][j]){
							cnt++;
							quq.push_back(owo[cc]);
							break;
						}
					}
				}
				if(cnt >= m){
					ans += pow(2,i);
					owo = quq;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
