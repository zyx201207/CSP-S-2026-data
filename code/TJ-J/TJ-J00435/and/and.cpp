#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const int N = 2e5 + 5;
struct node{
	int cal_0b,num;
}a[N];
int cal(long long a){
	int k = 0;
		while(a){
		k += a & 1;
		a >>= 1; 
	}
	return k;
}
bool cmp(node a,node b){
	if(a.cal_0b != b.cal_0b)return a.cal_0b > b.cal_0b;
	return a.num > b.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i].num;
		a[i].cal_0b = cal(a[i].num);
	}
	sort(a + 1,a + n + 1,cmp);
	ans = a[1].num;
	for(int i = 2;i <= m;i++) ans &= a[i].num;
	cout <<ans; 
	return 0;
} 
