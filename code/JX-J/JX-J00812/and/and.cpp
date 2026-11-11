#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],num;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			num=max(num,a[i]);
		}
		cout<<num;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				num=max(num,a[i]&a[j]);
			}
		}
		cout<<num;
		return 0;
	}
	if(m==n){
		num=a[1];
		for(int i=2;i<=n;i++){
			num=num&a[i];
		}
		cout<<num;
		return 0;
	}
}
