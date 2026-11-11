#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[100005];
bool flagA(){
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]) return false;
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(flagA()){
		for(int k=1;k<=n;k++){
			c[a[k]]++;
			for(int i=k+1;i<=n;i++){
				if(a[i]!=a[i-1]) c[a[i]]++;
			}
		}
	}
	else if(n>5&&m<=2){
		for(int i=1;i<=n;i++){
			c[a[i]]++;
			if(a[i]!=a[n]) c[a[n]]++;
		}
	}
	else{
		for(int k=1;k<=n;k++){
			for(int i=k;i<=n;i++){
				c[a[i]]++;
				for(int j=i+1;j<=n;j++){
					if(a[i]==a[j]){
						c[a[i]]--;
						i=j-1;
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
