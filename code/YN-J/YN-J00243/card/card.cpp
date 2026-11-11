#include<bits/stdc++.h>
using namespace std;
int n,m,top;
int a[500005],b[300005];
vector<int> t;
int findd(int k){
	for(int i = 0;i <= top;i++){
		if(t[i] == k) return i;
	}
	return top;
}
void tj(){
	for(int i = 0;i < top;i++){
		b[t[i]]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			t.push_back(a[j]);
			top++;
			int p = findd(a[j]);
			for(int k = top;k > p;k--){
				t.pop_back();
				top--;
			}
			tj();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << b[i] << ' ';
	}
	return 0;
}
