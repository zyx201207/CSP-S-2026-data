#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		cout << n;
		return 0;
	}
	else if(m==2){
		if(n<=5){
			int p=0,q=0;
			for(int i=n;i>=1;i--){
				if(a[i]==1) p=max(p,i);
				if(a[i]==2) q=max(q,i);
			}
			cout << p << " "  << q;
			return 0; 
		}
	}
	return 0;
}
