#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,a[200005],x;
	cin >> n >> m;
	for(int i=0;i<200005;i++){
		a[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]>a[i]){
				x=a[j];
				a[j]=a[i];
				a[i]=x;
			}
		}
	}
	cout << a[m];

	//fclose(stdin);
	//fclose(stdout); 
	
	return 0;
}

