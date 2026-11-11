#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
	char c;
}m[200005];
int n,a[200005],mx,mi,cnt,cnt1;
char b[10000005];
bool flag,gg,fg;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>m[i].c;
		if(flag==1&&m[i].c==m[i-1].c&&i>1){
			flag=1;
		}
		else{
			flag=0;
		}
		if(gg==1&&a[i]==a[i-1]&&i>1){
			gg=1;
		}
		else{
			gg=0;
		}
		m[i].l=a[i-1]+1;
		m[i].r=a[i]+a[i-1];
		if(a[i]<=500){
			for(int j=m[i].l;j<=m[i].r;j++){
				b[j]=m[i].c;
			}
		}
		mx+=a[i];
	}
	if(flag==1){
		cout<<"0";
		return 0;
	}
	if(gg==1){
		for(int i=1;i<=n;i++){
			if(m[i].c!=m[n-i+1].c){
				cnt+=(m[i].r-m[i].l);
			}
		}
		cout<<cnt;
		return 0;
	}
	if(n%2==0){
		for(int i=1;i<=n;i++){
			if(fg==1&&(m[i].r-m[i].l)==(m[n-i+1].r-m[n-i+1].l)){
				fg=1;
			}
			else{
				fg=0;
			}
		}
		if(fg==1){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=mx/2;i++){
		if(b[i]!=b[mx-i+1]){
			cnt1++;
		}
	}
	cout<<cnt1;
	return 0;
}