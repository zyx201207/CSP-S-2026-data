#include<bits/stdc++.h>
using namespace std;
char a[200005];
int n,num[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		a[i]=c;
		num[i]=x;
	}
	int l=1,r=n;
	for(int i=1;i<=1000000&&l<=r;i++){
        int t=min(num[l],num[r]);
		if(a[l]!=a[r]){
			ans+=t;
		}
		num[l]-=t;
		num[r]-=t;
		if(num[l]==0){
			l++;
		}else if(num[r]==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
