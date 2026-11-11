#include<bits/stdc++.h>
using namespace std;
char b[100005];
const int N=1e5+10;
int a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> b[i];
	}
	long long ans=0;
	if(n==1){
		cout << 0;
	}
	else {
		int l=1,r=n;
		while(l<r){
			if(b[l]==b[r] && l!=r-1){
				continue;
			}else if(b[l]==b[r] && l==r-1){
				break;
			}
			else {
				int he=min(a[l],a[r]); 
				ans+=he;
			}
			l++;r--;
		}
	}
	cout << ans;
	return 0;
} 

