#inclue <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin >> m >> n;
	int a[100000];
	for(int i=0;i<=m;i++){
		if(a[i]>=m){
			cout << min(m);
		}
		else{
			cout << a[i];
		}
	}
	return 0;
}
