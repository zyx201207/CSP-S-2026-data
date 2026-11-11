#include <bits/stdc++.h>
#include <cmath>
using namespace std;
long long n,m;
long long a[200001];
string s[200001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort (a+1,a+n+1,cmp);
    cout << a[m];
	return 0; 
} 
