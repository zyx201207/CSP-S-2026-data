#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[n],b[m],mx=0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[j]=a[i]%2+a[i]/2%2*10+a[i]/2/2%2*100+a[i]/2/2/2%2*1000;
			b[j+1]=a[i+1]%2+a[i+1]/2%2*10+a[i+1]/2/2%2*100+a[i+1]/2/2/2%2*1000;
			if(b[j]==b[j+1])
			{
				mx = a[i];
			}
		}
	}
	cout << mx;
	return 0;	
}
