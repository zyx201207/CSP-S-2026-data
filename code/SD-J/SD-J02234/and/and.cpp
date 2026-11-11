#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int b=m,c=1;
	int max=a[c];
	while(b){
		b--;
		for(int i=1;i<=n;i++){
			if(max<=a[i]) c=i; 
			else{
				int min=a[i];
				a[i]=max;
				a[c]=min;
				c=i;
			}
		}
	}
	cout<<a[n-m];
	return 0;
}
