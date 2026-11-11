#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

long long a[200005];

int main() {
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m,lt,sum;
	cin >> n >> m;
	if(m==1){
		cin>>a[1];
		lt=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			lt=max(lt,a[i]);
		}
		cout<<lt;
		return 0;
	}else if(m==n){
		cin>>a[1];
		sum=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			sum=sum&&a[i];
			
		}
		cout<<sum;
	}else if(m==n-1){
		cin>>a[1];
		sum=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			sum=sum&&a[i];
		}
		lt=sum&&a[1];
		for(int i=2;i<=n;i++){
			lt=max(lt,sum&&a[i]);
		}
		cout<<lt;
	}
	return 0;
}