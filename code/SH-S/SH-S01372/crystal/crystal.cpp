#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+5;
ll n,a[maxn],d[maxn],s[maxn],m,v = 0,k;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >>m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		d[i] = a[i] - a[i-1];	
		
	}
	for(int i = 1;i < n;i++){
		s[i] = d[i+1] + s[i-1];
	}
	int i = 1;
	while(s[i] <= m){
		v += a[i];
		i++;
	}	
	k = upper_bound(a+1,a+n+1,v/(i-1)) - a;
	ll cnt =0;
	for(int yi = 1;yi <= n;yi++){
		cout << d[i] << " " << yi << endl; 
		if(d[i] < yi){
			cnt++;
		}
	}
	cout << cnt;
	fclose(stdin);
 	fclose(stdout); 
	
}
