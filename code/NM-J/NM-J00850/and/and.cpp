#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	int c=n-m+1;
	for(int i=1;i<=c;i++){
		int o1=i;
		while(--m){
			for(int j=o1+1;j<=n;j++){
				int e=0;
				int y=j;
				e=y&y;
				if(sum<e){
					sum=e;
				}
			}
			o1++;
		}
	}
	cout<<sum;
	return 0;
}
