#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],res=0;
bool v[200010];
int main(){
	//freopen("E:/down/and/and5.in","r",stdin);
	//freopen("E:/down/and/and.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=32;i>=0;i--){
		long long cont=0;
		for(int j=1;j<=n;j++){
			if(((a[j]>>i)&1)==1&&v[j]==0){
				cont++;
			}
		}
		if(cont>=m){
			res=res|(1<<i);
			for(int j=1;j<=n;j++){
				if(((a[j]>>i)&1)==0){
					v[j]=1;
				}
			}
		}
	}
	cout<<res;
	return 0;
}