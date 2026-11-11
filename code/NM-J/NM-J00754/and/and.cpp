#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[200001],m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;i<=n;j++){
				if(a[i]<a[j])swap(a[i],a[j]);
			}
		}
		cout<<a[1];
	}
}
