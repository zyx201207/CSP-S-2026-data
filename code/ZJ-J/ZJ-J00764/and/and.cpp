#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
struct node{
	int x,len,sum1;
}a[N];
int n,m;
void js(int i){
	int tmp = a[i].x;
	while(tmp){
		if(tmp % 2 == 1){
			a[i].sum1++;
		}
		a[i].len++;
		tmp /= 2;
	}
}
bool cmp(node x,node y){
	if(x.len != y.len){
		return x.len > y.len;
	}
	return x.sum1 > y.sum1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x;
		js(i);
	}
	sort(a + 1,a + 1 + n,cmp);
	int ans = a[1].x;
	for(int i = 2;i <= m;i++){
		ans &= a[i].x;
	}
	cout << ans;
	return 0;
}