#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,ans=0,f[50];
string a[200005];//a[i]:第i个数的二进制 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		while(x){
			a[i]+=(char)x%2+48;
			x/=2;
		}
	}
	sort(a+1,a+n+1);
	for(int j=30;j>=0;j--){
		int sum=0;
		for(int i=n;i>=1;i--){
			if(a[i].size()<=j||a[i][j]=='0'){
				continue;
			}
			int F=1;
			for(int k=1;k<=cnt;k++){
				if(a[i].size()<=f[k]||a[i][f[k]]=='0'){
					F=0;
					break;
				}
			}
			if(F){
				sum++;
			}
		}
		if(sum>=m){
			f[++cnt]=j;
		}
	}
	for(int i=1;i<=cnt;i++){
		int num=1;
		for(int j=1;j<=f[i];j++){
			num*=2;
		}
		ans+=num;
	}
	cout<<ans;
	return 0;
} 
