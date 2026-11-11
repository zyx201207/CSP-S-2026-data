#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,a[5000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+1);
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			a[i]=a[i+1];
		}
	}
	return 0;
	
}
