#include<bits/stdc++.h>
using namespace std;
struct number{
	int cnt;
	long ai;
}a[200005];
int cntone(int n){
	int cnt=0;
	while(n){
		if(n%2){
			cnt++;
		}
		n>>=1;
	}
	return cnt;
}
bool cmp(number a,number b){
	return a.cnt>b.cnt||a.ai>b.ai;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i].ai;
	}
	for(int i=0;i<n;i++){
		a[i].cnt=cntone(a[i].ai);
	}
	sort(a,a+n,cmp);
	int awser=a[0].ai;
	for(int i=1;i<m;i++){
		awser&=a[i].ai;
	}
	cout << awser;
	return 0;
}
