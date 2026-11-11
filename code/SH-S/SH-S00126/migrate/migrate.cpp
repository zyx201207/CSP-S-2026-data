#include<bits/stdc++.h>
using namespace std;
int c,t,n,l,ans;
long long m,a[2000010],b[2000010],d[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	for(int itt = 1;itt <= t;itt++){
		cin >> n >> m;
		l = 1;
		ans = 0;
		memset(d,0,sizeof(d));
		memset(b,0,sizeof(b));
		
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			d[i]++;
			while(a[l] + m < a[i]){
				if(a[l] + m >= a[i - 1]){
					b[l] = i - 1;
				}
				else{
					b[l] = l;
				}
				d[i - 1]++;
//				cout << i - 1 <<" %";
				l++;
			}
		}
		for(int i = l;i <= n;i++){
			if(a[i] + m >= a[n]){
				b[i] = n;
			} 
			
		}
		for(int i = 1;i <= n;i++){
			if(b[i] <= 2)continue;
			if(b[i] == i+ 1)continue;
////			cout << i << "   "<< b[b[i] - 1] << " " << b[b[i]-2] << "#\n";
			ans = ans + (b[b[i] - 1] - b[b[i]-2]) * d[i];
//			cout << ans << " ";
		}
		cout << ans << "\n";
	}
	
} 
