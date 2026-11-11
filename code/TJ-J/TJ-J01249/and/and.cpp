#include<bits/stdc++.h>
using namespace std;
int l[200005],t,n,m;
void dfs(int x,int ans,int e){
	if(x>m){
		t=max(t,ans);
		return;
	}
	for(int i=e;i<=n;i++){
		dfs(x+1,ans&l[i],i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int o=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if(l[i]=='0'){
			o++;
		} 
	}
	sort(l+1,l+1+n);
	if(m==1){
		cout<<l[n];
		return 0;
	}
	if(n-m<o){
		cout<<0;
		return 0;
	}
	if(n<=2000&&m==2){
		int h=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				h=max(h,l[j]&l[i]);
			}
		}
		cout<<h;
		return 0;
	}
	if(n==m){
		int g=l[1];
		for(int i=2;i<=n;i++){
			g=g&l[i];
		}
		cout<<g;
		return 0;
	}
	if(n<=20){
		dfs(1,2147483647,1);
		cout<<t;
		return 0;
	}
	if(l[n]<=4){
		int a=0,b=0,c=0,d=0;
		for(int i=1;i<=n;i++){
			if(l[i]==4){
				a++;
			}
			if(l[i]==3){
				b++;
			}
			if(l[i]==2){
				c++;
			}
			if(l[i]==1){
				d++;
			}
		}
		if(a>m){
			cout<<4;
		}else if(a+b>m){
			cout<<3;
		}else if(a+b+c>m){
			cout<<2;
		}else{
			cout<<1;
		}
		return 0;
	}
	cout<<l[n-m+1];
	return 0;
}
