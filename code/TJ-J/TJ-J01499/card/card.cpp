#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int sum[500005];
void ci(int x){
	int bi=x,bj;
	for (int i=x;i<=n;i++){
		bool ac=1;
		for (int j=1;j<=n;j++){
			if (b[j]==a[i]){
				ac=0;
				bj=j;
			}
		}
		if (ac){
			b[bi]=a[i];
			bi++;
		}else{
			for (int j=bj;j<=bi;j++){
				b[j]=0;
			}
			bi=bj;
			b[bi]=a[i];
			bi++;
		}	
	}
	for (int i=x;i<=bi;i++){
		if (b[bi]!=0){
			sum[b[bi]]++;
		}
		
	}
}
int main (){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin >>  n>>m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		
	}
	for (int i=1;i<=n;i++){
		ci(i);
		
	}
	for (int i=1;i<=m;i++){
		cout << sum[i] << " ";
		
	}
}

