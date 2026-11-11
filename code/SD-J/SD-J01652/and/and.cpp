#include<bits/stdc++.h>
using namespace std;
long long k,a[200009],n,m,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	m=a[1];
	for(int i=2;i<=n;i++){
		if(k==1){
			m=max(m,a[i]);
		}
		else if(k==n){
			m=(m&a[2]);
		}
	}
	if(k==2){
		for(int  i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=(a[i]&a[j]);
				m=max(m,s);
			}
		}
	}
	cout<<m;
}
