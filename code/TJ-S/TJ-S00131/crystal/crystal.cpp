#include<bits/stdc++.h> 
using namespace std;
int p[100000][2];
int ans2,n,m;
void f(int a[1000000],int l,int r){
	if(r==0){
		int u=1;
		for(int i=1;i<=l;i++){
			bool o=true;
			for(int j=1;j<=l;j++){
				if(a[i]==p[j][1]){
					o=false;
					p[j][2]++;
					break;
				}
			}
			if(o==false) continue;
			p[u][1]=a[i];
			p[u][2]=1;
			u++;
		}
		int ans1=0;
		for(int i=1;i<=u;i++){
			ans1=max(ans1,p[i][2]);
		}
		ans2=max(ans1,ans2);
		return;
	}
	for(int i=1;i<=l;i++){
		a[i]++;
		f(a,l,r-1);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n+5];
	f(a,n,m);
	cout<<ans2;
	return 0;
	
}
