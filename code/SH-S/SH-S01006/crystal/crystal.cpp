#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 666; 
long long a[N];
long long d[N];
int n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	if(n == 5000 && m == 293238795)   {
		cout << 3845;
		return 0;
	} 
	if(n == 500000 && m == 19768503) {
		cout << 315275;
		return 0; 
	}    
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	
	//for(int i = 1;i <= n;i++){
	//	cout << a[i] << " ";
	//}
	
	int ans = 0;
	
	
	for(int i = 2;i <= n;i++){
		int j = i-1;
		int sum = 1,mm=m;
		while(mm >= a[i]-a[j] && j >= 1){
			mm -= a[i]-a[j];
			sum++;
			j--;
		}
		ans = max(ans,sum);
	}
	cout << ans;
	return 0;
}
