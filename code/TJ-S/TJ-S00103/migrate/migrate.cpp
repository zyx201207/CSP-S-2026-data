//migrate
#include<bits/stdc++.h>
using namespace std;
//1000MB => 262144000 int=> 131072000 long long
//          40004200110

int c,t;
int n,d;
int x[200010],xs[200010];
map<int,int> ans;
int ans1[200010];

int i,j,f,ct;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	for(int k = 0;k < t;k++){
		cin >> n >> d;
		f = 1;
		xs[1] = 0;
		cin >> x[1];
		ct = 0;
		bool b = false;
		for(i = 2;i <= n;i++){
			xs[i] = 0;
			cin >> x[i];
			ans[i] = 0;
			while(f < i){
				if(abs(x[i]-x[f]) <= d){
					break;
				}else{
					f++;
					if(f == i){
						b = true;
					}
				}
			}
			if(b) continue;
			for(j = f;j < i;j++){
				ans[i] += 1;
				ans[j] += 1;
				if(ans[i] == 2 || ans[j] == 2){
					ans1[i] = j;
					ans1[j] = i;
				}
				
			}
		}
		for(i = 1;i <= n;i++){
			if(ans[i] == 2){
				ct++;
				//cout << i << " " <<endl;
			}else{
				if(ans[ans1[i]] == 2){
					ct++;
					//cout << i << " " <<endl;
				}
			}
		}
		cout << ct/2 << endl;
	}
	return 0;
} 
