#include<bits/stdc++.h>
using namespace std;
int a[20010];
string b[20010];
int cmp(string a1,string b1){
	int x1=a1.size();
	int h=0,b=x1-1;
	for(int i=0;i<x1;i++){
		if(a1[i]==b1[i]){
			h+=int(a1[i]-48)*pow(2,b);
		}
		b--;
	}
	return h;
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxv=-1;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		while(x){
			char m=char(x%2+48);
			x/=2;
			b[i]=m+b[i];
		}
		maxv=max(maxv,int(b[i].size()));
	}
	for(int j=1;j<=n;j++){
		if(int(b[j].size())<maxv){
			int o=maxv-int(b[j].size());
			while(o--){
				b[j]='0'+b[j];
			}
		}
	}
	int maxn=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(cmp(b[i],b[j]),maxn);
			}	
		}
	cout<<maxn;
	return 0;
}
