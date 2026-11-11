#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c,max=0,b=0;
	cin >> n >> m;
	int a[100005];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	if (m==1){
		cout << a[n-1];
	}
	else {
		for(int i=0;i<n;i++){
			b=a[i];
			for(int j=0;j<m;j++){
				
				b=b&a[i+j];
				
			
			}
			if(b>max){
				max=b;
			}
		}
		cout << max;
		
	}
	
	return 0;
}
