#include<bits/stdc++.h>
using namespace std;

int n,m,a[1000001],w=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("crad.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[i+1]){
			w=1;	
		}
	}
	if(w==0){
		cout << n;
	}
	return 0;
}