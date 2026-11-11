#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","w","stdout");
	int n,m,a[500010]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=m,num=0;
	for(int i=1;i<=n;i++){
		num+=a[i];
		if(num>a[n]||num+l>a[n]){
			cout<<i;
			return 0;
		}else{
			if(l+a[i]==a[i+1]){
				num+=a[i+1]-a[i];
				l-=a[i+1]-a[i];
			}else{
				num+=l;
				l=0;
			}
		}
	}
	return 0;
}
