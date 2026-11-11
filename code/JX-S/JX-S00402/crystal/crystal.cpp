#include<bits/stdc++.h>
using namespace std;
long long key,num,n,m,a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			m=m-a[i]+a[j];
			if(m<0){
				for(int k=1;k<=n;k++){
					a[k]=b[k];
				}
				break;
			}
			a[j]=a[i];
		}
		if(m<=0){
			break;
		}
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[1]){
			num++;
		}
	}
	cout<<num;
}
