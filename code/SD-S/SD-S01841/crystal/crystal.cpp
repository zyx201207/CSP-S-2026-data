#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int a[100010];
	int b[100010];
	b[0]=0;
	int n;
	int m;
	cin >> n;
	cin >> m;
	
	int t=0;
	int ans = 0;
	int i1;
	int j;
	
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	
	int ans1 = 1;
	for(int i = 0;i<n-1;i++){
		i1=n-2-i;
		ans1--;
		t = 0;
		while(t<=m && ans1 <= i1+1){
			ans1++;
			int h = 0;
			t = 0;
			while(ans1 - h > 0 && i1 - h > 0){
				t = t + b[i1-h] * (ans1 - h);
				h++;
			}
		}
		
		ans = max(ans,ans1);
	}
	cout << ans;
	
	
	return 0;
} 
