#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,out,re1,cc;
bool judge=false;
int a[1000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sort(a+1,a+n+1);
	}
	for(int i=a[1];i<=a[n];i++){
		for(int k=1;k<=n;k++){
			if(a[k]>i){
				break;
			}
			re1=k;
			if(a[k]==i)judge=true;
	}
		for(int j=re1;j>0;j--){
			cc+=i-a[j];
			if(cc>=m){
				ans=re1-j+1;
				cc=0;
				break;
			}
	}
	out=max(ans,out);
	}
	cout<<out;
	return 0;
}
