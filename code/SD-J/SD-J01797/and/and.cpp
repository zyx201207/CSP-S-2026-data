#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[201000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j,sum = -1;
	cin>>n>>m;
	for(i = 1;i <= n;i ++){
		cin>>a[i];
	}
	if(m == 1){
		for(i = 1;i <= n;i ++){
			if(a[i] > sum) sum = a[i];
		}
	} 
	if(m == 2){
//		for(i = 1;i <= n;i ++){
//			
//		}
		for(i = 1;i <= n;i ++){
			for(j = i + 1;j <= n;j ++){
				if(a[i] & a[j] > sum)  sum = a[i] & a[j];
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
