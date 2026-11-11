#include <bits/stdc++.h>
using namespace std;
int n,m,pos = 1,a[200005],num[3000005][2],flag[3000005];
void merge(int x){
	int root = 1;
	for(int i = 29;i>=0;i--){
		if(x & (1<<i)){
			if(num[root][1] == 0){
				num[root][1] = ++pos;
			}
			root = num[root][1];
		}else{
			if(num[root][0] == 0){
				num[root][0] = ++pos;
			}
			root = num[root][0];
		}
		flag[root]++;
	}
	return ;
}
int find(){
	int root = 1,ans = 0;
	for(int i = 29;i>=0;i--){
		if(num[root][1] && flag[num[root][1]] >= m){
			ans += (1<<i);
			root = num[root][1];
		}else{
			root = num[root][0];
		}
	}
	return ans;
}
int main(){
	/*while(true){
		fuck(CCF);
	}*/
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		merge(a[i]);
	}
	cout<<find();
	return 0;
}