#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,a[100005],MAX = 0,c;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(m == 2){
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			MAX = max(a[i]&a[j],MAX);
		}
	}	
	}
	if(m==1)for(int i = 1;i <= n;i++)MAX = max(a[i],MAX);
	if(m==n-1){
		for(int i = 2;i <= n;i++){
			a[1] &= a[i];
		}
		cout << a[1];
		return 0;
	}
	if(m == n){
		for(int i = 1;i <= n;i++){
			a[1] &= a[i];
		}
		cout << a[1];
		return 0;
	}
	cout << MAX;
	return 0;
}
