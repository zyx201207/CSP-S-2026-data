#include <bits/stdc++.h>
using namespace std;

	long long int n,m,m1,b = 0,a[50002];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}	
	for(int i = 1;i<n;i++){
		for(int j = i;j<=n;j++){
			if(a[j]<a[i]){
				b = a[i];
				a[i] = a[j];
				a[j] = b;
				}
			}
		}
	long long int maxb = 0;
	for(int i = n;i>0;i--){	
		m1 = m;
		b = 0;
		for(int j = i;m1>0 && j>0;j--){
			if(a[j]!=0){
				if(m1>=a[i]-a[j]){
				b++;
				m1 = m1-a[i]+a[j];
				}else{
					break;
					}			
			}
			}
			maxb = max(maxb,b);
		}
	cout << maxb;
	return 0;
	}
