#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int s[200005];
	char a[200005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>a[i];
	}
	
	int m[200005];
	m[1]=s[1];
	for(int i=2;i<=n;i++){
		m[i]=m[i-1]+s[i];
	}
	
	int ans=0;
	int j=1,k=n;
	for(int i=1;i<=m[n]/2;i++){
		if(m[j]<i){
			j++;
		}
		if(m[k]>m[n]-i+1){
			k++;
		}
		if(a[j]!=a[k]){
			ans++;
		}
	}
	cout<<ans;
}



