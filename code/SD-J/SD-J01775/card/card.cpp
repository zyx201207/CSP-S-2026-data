#include <bits/stdc++.h>
using namespace std;
int v[200005],ans[200005];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	long long n , m;
	long long a[200005];
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(long long i=1;i<=n;i++){
		
		
		for(long long j=i;j<=n;j++){
			v[a[j]] ++;
			if(v[a[j]] == 2){
				v[a[j]] --;
				
				long long t = j-1;
				while(a[t] != a[j]){
					v[a[t]]--;
					
					t--;
				}
			}
		}
		for(long long j=1;j<=m;j++){

			if(v[j] == 1){
				ans[j]++;
			} 
			v[j] = 0;
		}
	}
	
	for(long long i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
} 
