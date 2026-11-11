#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],pos[500005],sf[500005],sy[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int k = 1;k <= n;k++){
		
		for(int i = 1;i <= n;i++){
			pos[i] = 0;
			sf[i] = 0;
			sy[i] = 0;
		}
		int ans = 1;
		for(int i = k;i <= n;i++){
			int posi = 0;
			if(sf[a[i]] == 1){
				//cout << k << ' '<< i << endl;
				posi = sy[a[i]];
				//cout << posi << endl;
				for(int j = posi;j <= ans - 1;j++){
					//cout << k << ' '<< i << ' ' << pos[j] << endl;
					sf[a[j]] = 0;
					sy[a[j]] = 0;
					pos[j] = 0;	
					
				}
				
			}
			
			
			pos[ans] = a[i];
			sf[a[i]] = 1;
			sy[a[i]] = i;
			ans++;
			
			
		}
		for(int i = 1;i <= m;i++){
			if(sf[i] == 1){
				cnt[i]++;
				//cout << i << ' ';
			}
		}
		//cout << endl;
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
