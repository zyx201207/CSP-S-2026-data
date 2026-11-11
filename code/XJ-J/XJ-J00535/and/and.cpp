#include <bits/stdc++.h>
using namespace std;
const int climax = 2e5 + 5;
int n,m;
long long num[climax],one[35];
long long ans = 0;
queue<int> tmp1,tmpall,que;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> num[i];
		que.push(i);
	}
	for(int bit = 30;bit >= 0;bit --){
		while(!que.empty()){
			int id = que.front();que.pop();
			if((num[id] >> bit) & 1){
				one[bit] ++;
				tmp1.push(id);
			}tmpall.push(id);
		}
		if(one[bit] >= m){
			ans |= (1 << bit);
			while(!tmp1.empty()){
				que.push(tmp1.front());
				tmp1.pop();
			}
			while(!tmpall.empty()){
				tmpall.pop();
			}
		}else{
			while(!tmp1.empty()){
				tmp1.pop();
			}
			while(!tmpall.empty()){
				que.push(tmpall.front());
				tmpall.pop();
			}
		}
	}
	cout << ans << endl;
}
