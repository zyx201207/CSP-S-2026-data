#include <bits/stdc++.h>
using namespace std;
int arr[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	int cnt = 1;
	int maxn = 1;
	for(int j=1;j<n;j++){
		cnt = 1;
		for(int i=j;i<n;i++){
			int x = cnt*(arr[i]-arr[i-1]);
			if(m>=x){
				m-=x;
				cnt++;
			}
			else{
				break;
			}
		} 
		maxn = max(cnt,maxn);
		
	}

	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	
	

}

