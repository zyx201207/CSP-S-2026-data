include <bits/c++.h>
using namespace std;
int a[200001];
int main(){
	int n,m,i,j,c,b,d;
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin >> n;
	cin >> m;
	for (i=0;i<n;i++){
		cin >> b;
		a[i]=b;
	}
	for (i=1;i<m;i++){
		for (j=1;i<m;j++){
			c=a[i-1] and a[j-1];
			if (i==1 and j==1){
				d=c;
			}
			else{
				if (c>d){
					d=c;
				}
			}
		}
	}
	cout << d;
		freclose("and.in");
		freclose("and.out");
	return 0;
} 
