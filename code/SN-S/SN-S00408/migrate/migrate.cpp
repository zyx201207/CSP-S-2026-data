#include <bits/stdc++.h>
using namespace std;
const int MAX=2000000;
short c;
int t,ans;
long long n,a[MAX+5],d,x[20000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int cnt,max=20000000,bu=0;
		cin >> n >> d;
		for(int i = 1;i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n; i++){
			int l=i;
			int v=1;
			for(int j=i+1;j<=n;j++){
				bool flag=true;
				l=i;
				for(int t=i;t<=j;t++){
					if(a[t]-a[l]<=d){
						l=t;
						flag=true;
						bu++;
					}
					else{
						flag=false;
					}
					if(t==j && flag && bu<=max){
						max=bu;
						
						x[v]=bu;
						v++;
					}
					
				}
				for(int b=1;b<=v;i++)
				{
					if(x[b]==max){
						cnt++;
					}
				}
			}
			
			if(cnt==2){
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
