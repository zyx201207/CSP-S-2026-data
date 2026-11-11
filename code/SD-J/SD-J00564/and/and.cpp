#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int n,m,a[N],s[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=-2147483645;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn<<"\n";
		return 0;
	}
	else if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
		cout<<s<<"\n";
	}
	else if(m==2){
		int maxnn=-2147483645;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxnn=max(maxnn,a[i]&a[j]);
			}
		}
		cout<<maxn<<"\n";
	}
	else {
		cout<<"0\n";
	}
	return 0;
}
