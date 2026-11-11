#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
long long p,cnt;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>m;
		p+=m;
		cin>>b;
		for(int i=1;i<=m;i++){
			a+=b;
		}
	}
	if(p%2==0){
		for(int i=1,j=p;i<=p/2,j>=(p/2)+1;i++,j--){
				if(a[i]!=a[j]){
					cnt++;
			}
		}
		cout<<cnt;
		return 0; 
	}else{
		for(int i=1,j=p;i<=p/2,j>=(p/2)+2;i++,j--){
				if(a[i]!=a[j]){
					cnt++;
				}
		}
	}
	cout<<cnt;
	return 0;
}	
