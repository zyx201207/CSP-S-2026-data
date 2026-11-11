#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[200050];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout << a[n] <<endl;
	}
	else if(m==2){
		int ma = -1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int lx = a[i]&a[j];
				ma = max(ma,lx);
			}
		}
		cout << ma <<endl;
	}
	else if(m==n){
		int lx = a[1];
		for(int i=2;i<=n;i++){
			lx = lx&a[i];
		}
		cout << lx;
	}
	else if(m==n-1){
		int ma = -1;
		int lx;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				if(j==1) lx = a[1];
				else if(i==1&&j==2) lx = a[2];
				else lx = lx & a[j];
				
			}
			ma = max(ma,lx);
		}
		cout << ma << endl;
	} 
	
	return 0;
}
