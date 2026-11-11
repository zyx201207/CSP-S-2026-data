#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long int n,m,a[N],c,flag;
int kk(int x){
	for(int i=1;i<=x;i++){
		for(int j=i;j<=i+m;j++){
			if(j!=i){
				return a[j]&a[i];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=i+m;j++){
			if(m==2){
				if(a[i]&a[j]>c&&i!=j){
					c=a[i]&a[j];
				}	
			}else if(m==1){
				flag=1;
				break;
			}else{
				for(int i=1;i<=m;i++){
					kk(n);
				}
				c=kk(n);
			}
		}
		if(flag==1&&a[i]>c){
			c=a[i];
		}
	}
	cout<<c;
	return 0;
}