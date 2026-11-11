#include<bits/stdc++.h>
using namespace std;
int a[500007],cnt[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	//cout << "1234567\n";
	for(int i = 1;i <= m;i++){
		cnt[i] = 0;
	}
	//cout << "1234567\n";
	for(int i = 0;i < n;i++){
		//cout << i << '\n';
		cin >> a[i];
		//cout << i << "h\n";
	}
	//cout << "1234567\n";
	for(int i = 0;i < n;i++){
		//cout << "1234567\n";
		stack <int> stk;
		bool isin[m+1];
		for(int j = 1;j <= m;j++){
			isin[j] = false;
		}
		//cout << "1234567\n";
		while(!stk.empty()) stk.pop();
		//cout << "1234567\n";
		for(int j = i;j < n;j++){
			//cout << "1234567\n";
			if(isin[a[j]]){
				int x;
				//cout << "1234567\n";
				do{
					//if(stk.empty()) break;
					x = stk.top();
					isin[x] = false;
					stk.pop();
					//cout << "1234567\n";
				}while(x != a[j]);
			}
			stk.push(a[j]);
			isin[a[j]] = true;
		}
		//cout << "1234567\n";
		while(!stk.empty()){
			int x = stk.top();
			cnt[x]++;
			stk.pop();
		}
		//cout << "1234567\n";
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
