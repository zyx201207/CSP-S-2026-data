//SN-J00797 霍彧昂 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n,m,num;
int a[N],b[N],s[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	bool flag = true;
	for(int i = 1; i <= n; i++){
		flag = 1;
		for(int j = i; j <= n; j++){
			for(int k = 1; k <= j-1; k++){
				if(b[k] == a[j]){
					flag = 0;
					num = k;
					break;
				}
			}
			if(flag == 1) b[j] = a[j];
			else{
				for(int k = num; k <= j-1; k++) b[k] = 0;
				b[j] = a[j];
			}
		}
		for(int j = i; j <= n; j++) s[b[j]]++;
	}
	
	for(int i = 1; i <= m; i++) cout << s[i] << ' ';
	return 0;
}
