#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n;
int m;
long long s[200005];
bool cmp(const int x,const int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			s[i]=a[i]&a[j];
		}
	}
	sort(s+1,s+n+1,cmp);
	cout << s[1] << endl;
	return 0;
}
