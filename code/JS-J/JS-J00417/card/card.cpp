#include<bits/stdc++.h>
using namespace std;

int m,n;
int cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n+2];

	
	int f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(cnt[a[i]]>=1){
			f=i;
		}
		
		for(int j=f;j<=i;j++){
			cnt[a[j]]++;
		}
		
		
			
		
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}

	
	return 0;
}
