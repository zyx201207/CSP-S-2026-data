#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int t[N], ans[N];
struct st{
	int num;
	int bf;
}arr[N];
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i].num;
		/*if(t[arr[i].num] == 0)
			t[arr[i].num] = i;
		
		if(t[arr[i].num] != 0){
			arr[i].bf = t[arr[i].num];
			t[arr[i].num] = i; 
		}
		else if(arr[i].bf == 0) arr[i].bf = i;*/
	}
	//for(int i = 1; i <= n; i++){
		//cout << arr[i].bf << endl;
	//}
	for(int i = 0; i < n; i++){
		int nw = 0;
		for(int j = i + 1; j <= n; j++){
			nw *= 10;
			nw += arr[j].num;
			if(t[arr[j].num] != 0){
				int sz = j - t[arr[j].num] + 1;
				for(int k = 1; k <= sz; k++){
					nw /= 10;
					t[arr[j - sz + i + k].num] = 0;
				}
				nw *= 10;
				nw += arr[j].num;
				
			}
			t[arr[j].num] = j;
			//cout << t[arr[j].num] << "x"<<  endl;
			
			//if(arr[j].bf != 0 && arr[j].bf >= i + 1 && arr[j].bf != j && arr[j].bf >= ls){
				//ls = j;
				//for(int k = 1; k <= j - arr[j].bf + 1; k++){
					//nw /= 10;
				//}
				//nw *= 10;
				//nw += arr[j].num;
			//} 
			
			
			//cout << nw << endl;
		}
		while(nw > 0){
			ans[nw % 10]++;
			nw /= 10;
		}
		//cout << "================" << endl;
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
