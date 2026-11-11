#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N =2e5 + 5;
LL n,m,k[N];
LL max_ = INT_MIN;
bool cmp(int x,int y){
	return  x > y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i <n;i++){
		cin >> k[i];
	}
	
	sort(k,k+n,cmp);
	LL x = 0;
	for(int i = 0;i < n-m;i++){
		for(int j=i;j<i+m-1;j++){
			x = k[j] & k[j+1];
		}
		max_ = max(x,max_);
	}
	cout << max_;
	return 0;


	

	
}