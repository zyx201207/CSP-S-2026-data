#include<bits/stdc++.h>
using namespace std;

long long n,m,cnt,sum,e,h = 1,q;
long long a[500010],p[500010];
bool f;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		if(a[i] != a[i - 1]){
			p[++q] = i;
		}
	}
	
	for(int i = 1;i <= n;i++){
		sum += a[i];
		if(a[i] != a[i - 1]){
			e++;
		}
		
		if(e * a[i] - sum > m){
			f = 0;
			int k = e;
			while(1){
				if(a[p[k]] == a[p[k] + 1] && e * a[i] - (sum - a[i] + a[p[k]]) <= m){
					f = 1;
					break;
				}
				
				if(k > q){
					break;
				}
				
				k++;
			}
			
			if(f == 0){
				break;
			}
			
			i = p[k] - 1;
			sum -= a[h];
			sum -= a[i];
			h++;
			cnt--;
			if(a[h] != a[h - 1]){
				e--;
			}
			
			if(e * a[i] - sum > m){
				break;
			}
		}
		
		cnt++;
	}
	
	cout<<cnt;
	return 0;
}
