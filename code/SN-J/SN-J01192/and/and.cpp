#include <bits/stdc++.h>
using namespace std;
//847-900
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	long long n,m;
	cin >> n >> m;
	int max=0;
	int a[n+5];
	for(long long i=0;i<n;i++){
		cin >> a[i];
	}
	if(m=1){
		for(int i=0;i<n;i++){
			if(a[i]>max) max=a[i];
		}
		cout << max;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(n==3){
				for(int k=j+1;k<n;k++){
					int x=a[i]&a[j]&a[k];
					if(x>max) max=x;
				}
			}else{
				int x=a[i]&a[j];
				if(x>max) max=x;
			}
		}
	}
	cout << max;
	//&
}
