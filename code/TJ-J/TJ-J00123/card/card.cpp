#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,k;
	cin >> m >> n;
	int a[100005],b[100005];
	for(int i=n; i>=0; i--) {
		cin >> a[i];
		b[i]=a[i-1];
		for(int j=0; j<=i; j--){
			if(b[j]==b[i]){
				while(j=0){
					b[j]=0;
					j--;
				}
			}
		}
		if(b[i]=i){
			k++;
		}
		
	}
	cout << k;
	return 0;
}
