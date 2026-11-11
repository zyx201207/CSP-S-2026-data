include <bits/c++.h>
using namespace std;
int a[500001];
int c[500001];
int main(){
	int n,i,m,b,d,j;
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	cin >> n;
	cin >> m;
	for (i=0;i<n;i++){
		cin >> b;
		a[i]=b;
	} 
	for (i=1;i<=n;i++){
		for (j=i;j<=n;j++){
			c[i]=a[i];
			for (d=0;d<j;d++){
				if (c[d]==c[j]){
					
				}
			}
		}
	}
		freclose("card.in");
		freclose("card.out");
	return 0;
}
