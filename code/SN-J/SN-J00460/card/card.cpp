#inclue <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		if(m>n){
			cout << m;
		}
		else{
			cout << n;
		}
	}
	cout << m << n;
	return 0;
}

