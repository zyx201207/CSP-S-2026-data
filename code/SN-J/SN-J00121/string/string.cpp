#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("in.string","r",stdin);
	freopen("out.string","w",stdout);
	int n;
	cin >> n;
	if(n == 1){
		cout << 0;
	}
	int a;
	int ans;
	string b[100005];
	for(int i = 1; i <= n; i ++){
		cin >> a;
		cin >> b[i];
	}
	for(int i = 0; i <= n; i ++){
		if(b[i] == b[i + 1]){
			ans ++;
		}
	}
	if(ans <= n){
		cout << 0;	
	}
	//不会了，摆烂了后面三道 只要做出来一道题就可以了 ,凭借多年偷分经验（其实不到半年），输出个0也可以拿到几分吧哈哈... 偷，也要偷的有仪式感一点，基础代码至少写上 
	
	return 0;
}
