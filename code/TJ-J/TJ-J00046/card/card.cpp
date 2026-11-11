#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],now[500005],first[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i < n;i++){ 
		for(int j = 1;j <= m;j++){
			first[j] = 0;
		}
		for(int j = i;j <= n;j++){
			int id = a[j];
			if(first[id] == 0){
				first[id] = j;
			}else{
				now[first[id]] = -2;
				now[j-1] = -1;
			}
		}
		int ed = 0;
		for(int j = i;j <= n;j++){
			if(now[j] == -2){
				ed++;
			}
			if(ed == 0){
				ans[a[j]]++;
			}
			if(now[j] == -1){
				ed--;
			}
			now[j] = 0;
		}
	}
	ans[a[n]]++;
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
