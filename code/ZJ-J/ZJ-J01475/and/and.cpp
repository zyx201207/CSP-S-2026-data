#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a;
	bool ok[51];
}o[200011];
int n,m,c[200011],top=0,c1[200011],top1=0;
bool ok[51];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>o[i].a;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if(((1<<j)&o[i].a)){
				o[i].ok[j]=1;
			}
			else{
				o[i].ok[j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		c[++top]=i;
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		top1=0;
		for(int j=1;j<=top;j++){
			if(o[c[j]].ok[i]==1){
				sum++;
				c1[++top1]=c[j];
			}
		}
		if(sum>=m){
			ok[i]=1;
			top=0;
			for(int j=1;j<=top1;j++){
				c[++top]=c1[j];
			}
		}
		else{
			ok[i]=0;
		}
	}
	long long ans=0;
	for(int i=30;i>=0;i--){
		if(ok[i]==1){
			ans+=(1<<i);
		}
	}
	cout<<ans<<'\n';
	return 0;
}