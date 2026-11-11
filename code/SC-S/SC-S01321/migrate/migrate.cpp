#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		vector<int> v(n);
		int sum[n]={0};
		int cnt = 1;
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		for(int i = 1; i < n; i++){
			sum[i-1]=v[i]-v[i-1];
			if(sum[i-1]<=d){
				cnt++;
			}else{
				break;
			}
		}
		int sums = sum[0]+sum[1];
		int tmp = 0,temp = 0;
		for(int i = 2; i < cnt; i++){
			int k = sums+sum[i];
			for(int j = sum[0]; j <= d; j++){
				if(k-j<=d && j+v[i]==v[i+1]){
					temp++;
				}
				sums+=sum[i];
			}
			if(temp%33==0){
				tmp++;
			}
		}
		cout<<tmp;
	} 
	return 0;
}