#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
int c,t,n;
long long d,sum;
long long a[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		sum = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		
		for(int i = 1;i <= n;i++){
			for(int j = i + 3;j <= n;j++){
				if(a[j] - a[i] <= d) continue;
				int cnt = 0;
				for(int k = i + 1;k <= j - 1;k++){
					if(a[k] - a[i] <= d && a[j] - a[k] <= d) cnt++;
				}
				if(cnt == 0) break;
				if(cnt == 2){
					int l1 = i,l2 = i+1,cntl = 0;
					while(l1 < l2 && l1 >= 1){
//						cout << l1 << " " << l2 << endl;
						cntl++;
						int nel1 = l1;
						while(nel1 >= 0){
							if(a[l1] - a[nel1] > d) break;
							nel1--;
						}
						l1 = nel1 + 1;
						int nel2 = l2;
						while(nel2 >= 0){
							if(a[l2] - a[nel2] > d) break;
							nel2--;
						}
						l2 = nel2 + 1;
					}
					int r1 = j,r2 = j - 1,cntr = 0;
					while(r1 > r2 && r1 <= n){
//						cout << r1 << " " << r2 << endl;
						cntr++;
						int ner1 = r1;
						while(ner1 <= n+1){
							if(a[ner1] - a[r1] > d) break;
							ner1++;
						}
						r1 = ner1 - 1;
						int ner2 = r2;
						while(ner2 <= n + 1){
							if(a[ner2] - a[r2] > d) break;
							ner2++;
						}
						r2 = ner2 - 1;
					}
					sum = sum + cntl * cntr;
				}
			}
		}
		cout << sum << endl;
	}
	
	return 0;
}