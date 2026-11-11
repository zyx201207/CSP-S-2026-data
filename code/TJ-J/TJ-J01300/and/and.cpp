#include <bits/stdc++.h>
using namespace std;
int a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	if(m==1){
		int ans=0;
		for(int i = 0;i<n;i++){
			int temp;
			cin >> temp;
			ans = max(temp,ans);
		}
		cout << ans;
	}else if(m==2){
		for(int i = 0;i<n;i++){
			cin >> a[i];
		}
		int ans=0;
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++){
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
	}else if(m==n){
		int ans;
		cin >> ans;
		for(int i = 1;i<n;i++){
			int temp;
			cin >> temp;
			ans = ans&temp;
		}
		cout << ans;
	}else if(m==n-1){
		int ans;
		for(int i = 0;i<n;i++){
			cin >> a[i];
		}
		for(int i = 0;i<n;i++){
			int temp=-1;
			for(int j = 0;j<n;j++){
				if(j==i)continue;
				if(temp==-1)temp=a[j];
				else{
					temp = temp & a[j];
				}
			}
			ans = max(ans,temp);
		}
		cout << ans;
	}else{
		int ans;
		for(int i = 0;i<n;i++){
			cin >> a[i];
		}
		sort(a,a+n,greater<int>());
		cout << a[m-1];
	}
	return 0;
}
