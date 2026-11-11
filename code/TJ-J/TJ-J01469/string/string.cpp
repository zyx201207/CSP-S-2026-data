#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+10;
int n,num=0,sum=0,ans;
int a[maxn];
char c[maxn];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(a[i]==1) num++;
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
		if(c[i]==c[i-1]) sum++;
	}
	if(num==n){
		cout<<n-1;
		return 0;
	}
	if(sum==n-1){
		cout<<0;
		return 0;
	}
	for(int i=n/2-1;i<n;i++){
		if(a[i]!=a[i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
