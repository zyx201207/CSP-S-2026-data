#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a,a+n+1);
	for(int i = 1;i<=n;i++){
		long long ans1 = 0,m1 = m;
		//cout << m1 << endl;
		for(int j = i;j<=n;j++){
			if(a[j]-a[i]>m1){
				break;
			}
			m1 = m1-(a[j]-a[j-1])*(j-i);
			//cout << m1 << " ";
			if(m1<0) break;
			ans1++;
			
		}
		//cout<< endl << ans1; 
		//cout << endl;
		ans = max(ans,ans1);
	}
	cout << ans;
	return 0;
} 
