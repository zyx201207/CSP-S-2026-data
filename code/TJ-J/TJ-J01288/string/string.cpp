#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<char> c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	a.push_back(0);
	c.push_back('0');
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin >> x >> y;
		a.push_back(x);
		c.push_back(y);
	}
	
	int l=1,r=n;
	long long cnt=0;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				l++;
				a[r]-=a[l];
			}
			else if(a[l]>a[r]){
				r--;
				a[l]-=a[r];
			}
			else{
				l++;
				r--;
			}
		}
		
		else{
			if(a[l]<a[r]){
				cnt+=a[l];
				l++;
				a[r]-=a[l];
			}
			else if(a[l]>a[r]){
				cnt+=a[r];
				r--;
				a[l]-=a[r];
			}
			else{
				cnt+=a[l];
				l++;
				r--;
			}
		}
	}
	
	cout << cnt << '\n';
	
	return 0;
}
