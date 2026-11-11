#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,m,a[500005],b[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(b[a[j]] == 0) {
				s.push(a[j]);
				b[a[j]]++;
			}
			else{
				while(s.top() != a[j]){
					b[s.top()]--;
					s.pop();
				}
			}
		}
		for(int j = 1;j <= m;j++){
			if(b[j] != 0) ans[j]++;
			b[j] = 0;
		}
		while(!s.empty()){
			//cout << s.top() << ' ';
			s.pop();
		}
		//cout << endl;
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
} 
