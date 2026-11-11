# include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+5;
int n,m; 
int a[N];
int maxx;
int main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int ant = a[i]&a[j];
			maxx = max(maxx,ant);
		}
	} 
	printf("%d",maxx);
	return 0;
}

