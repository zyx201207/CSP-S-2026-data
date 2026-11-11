#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int s[300005];
int ans[300005];
bool flag = true;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int k = 1;k <= n;k++){
		for(int i = k;i <= n;i++){
			for(int j = k;j < i;j++){
				if(a[i] == a[j]){
					s[j] = a[i];
					while(s[j] > 0){
						j++;
						s[j] = 0;
					}
					flag = false;
				}
			}
			if(flag) s[i] = a[i];
			flag = true;
		}	
//		for(int i = 1;i <= n;i++){
//			cout << s[i] << ' ';
//		}
//		cout << endl;
		for(int l = 1;l <= n;l++){
			ans[s[l]]++;
		}
		for(int i = k;i <= n;i++) s[i] = 0;
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
