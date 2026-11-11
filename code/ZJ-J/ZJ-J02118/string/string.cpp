#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	int l=1,r=n;
	char d;
	while(l<=r-1){
		if(c[l]!=c[r]){
			sum+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else{
			if(a[r]<a[l]){
				a[r]-=a[l];
				l++;
			}
			else{
				l++;
				r--;
			}	
		}
	}
	cout << sum;
	return 0;
}
