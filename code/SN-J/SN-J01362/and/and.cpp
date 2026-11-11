#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int max=0;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(a[i]&a[j]>max){
				max=a[i]&a[j];
			}
		}
	}
	cout<<max;
	return 0;
}
