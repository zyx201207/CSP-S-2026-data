#include<bits/stdc++.h>
using namespace std;
int n,m,am;
int a[10010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n-1;i++){
			if(a[i]<a[i+1]){
				am=a[i+1];
			}
		}
		cout<<am;
	}
	return 0;
}
