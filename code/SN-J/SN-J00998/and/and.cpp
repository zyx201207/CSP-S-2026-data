#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
string b[200005];
long long sum;
int vis[35];
int pos[200005];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		long long o=a[i];
		int cnt=0;
		while(o){
			cnt++;
			int w=o&1;
			char c=(char)w+'0';
			b[i]+=c;
			o>>=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<31;j++){
			if(b[i][j]=='1'){
				vis[j]++;
			}
		}
	}
	int f=0,fac=0;
	for(int i=30;i>=0;i--){
		if(vis[i]>=m){
			f=1;
			for(int j=1;j<=n;j++){
				if(b[j][i]=='1'){
					pos[++fac]=j;
				}
				if(fac==m){
					break;
				}
			}
			break;
		}
 	}
	if(f==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(i==1){
			sum=a[pos[i]];
		}else{
			sum=sum&a[pos[i]];
		}
	}
	cout<<sum;
	return 0;
}
