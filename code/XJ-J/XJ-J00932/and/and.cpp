#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",atdin)
	freout("string.out","r",atdin);
	int n,m;
	int a[200005];
	cin >> n >>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[i+1]||a[i]>a[i+1]){
			a[i]=a[i+1];
			a[i]=min(a[i],a[i+1]);
			cout<<a[i];
			break;
		}
	}	
	return 0;
}