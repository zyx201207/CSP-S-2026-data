#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010];
int b[100010],cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	sort(b+1,b+n+1);
	for(int i=2;i<=n;i++){
		cout << b[i];
	}
	for(int i=2;i<n;i++){
		if(m>=b[i]){
			if(b[i]<0){
				m+=abs(b[i]);
			}else{
				m-=b[i];
			}
			
			cnt++;
		}else{
			break;
		}
	}
	cout << cnt;
	return 0;
} 
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7
*/


