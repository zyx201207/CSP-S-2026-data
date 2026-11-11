#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans[100005];
bool b[1000005],c;
stack<long long> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i]; 
	}
	for(int i = 1; i<=n; i++){
		for(int j = i; j<=n; j++){
			int d = a[j];
			if(b[d]==1){
				while(s.empty()==0){
					int anss = s.top();
					b[anss] = 0; 
					s.pop();
				}
				int p = 1;
				while(1){
					if(a[p]==a[j]){
						break;
					}
					int anss = a[p];
					b[anss] = 1;
					s.push(a[p]);
					p++;
				}
			}else{
				b[d] = 1;
			}
			s.push(a[j]);
		}
		for(int j = 1; j<=m; j++){
			b[j] = 0;
		}
		while(s.empty()==0){
			int anss = s.top();
			ans[anss]++;
			s.pop();
		}
	}
	for(int i = 1; i<=m; i++){
		cout << ans[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
