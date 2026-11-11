#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[200005];

bool cmp(int a,int b){
	return a > b;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+1+n,cmp);
	
	int ans = a[1];

	if(m == 1){
		cout << a[1];
	}
	
	if(m == n){
		for(int i=2;i<=n;i++){
			ans = ans&a[i];
		}
		
		cout << ans;
	} 
	
	if(m == 2){
		vector<int> even;
		vector<int> odd;
		
		for(int i=1;i<=n;i++){
			if(a[i]%2 == 0){
				even.push_back(a[i]);
			}else{
				odd.push_back(a[i]);
			}
		}
		
		cout << max((even[0]&even[1]),(odd[0]&odd[1]));
	}
	
	
	
	return 0;
	
} 
