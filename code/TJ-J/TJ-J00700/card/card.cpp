#include<bits/stdc++.h>
using namespace std;
vector<char> s;
int n;
int m;
vector<int> ans;
vector<int> a;
vector<int> desk;
int check(int k, vector<int> a, int n){
	int ans = -1;
	for(int i = 0; i < n; i++){
		if(a[i] == k){
			ans = i;
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	/*
	10 3
	3 1 2 1 3 2 3 1 2 1
	*/
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cout << "aaa" << endl;
	}
	for(int x = 0; x < n; x++){
		int num = 0;
		
		for(int i = 0; i < n; i++){
			int k = a[i];
			
			if(check(k,desk,n) == -1 ){
				desk.push_back(k);
				num++;
			}
			else{
				for(int j = check(k,desk,n);j < num;j++){
					desk[j] = 0;
				}
			}
		}
		
		for(int che = 1; che <= m; che++){
			for(int q = 0; q < num; q++){
				if(desk[q] == che){

					ans[che-1]++;
				}
			}
		}
	}
	for(int i = 0; i < m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}


