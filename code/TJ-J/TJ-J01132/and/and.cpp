#include<bits/stdc++.h>
using namespace std;
int a[200000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int m,n;
	cin >> n>> m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout << a[1];
		return 0;
	}
	long long ans=a[1]&a[2];
	for(int i=3;i<=m;i++){
		ans=ans&a[i];
	}
	cout << ans;
	return 0;
} 
