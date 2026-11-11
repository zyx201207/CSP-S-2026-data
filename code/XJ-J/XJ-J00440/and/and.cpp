#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)
			maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxx=max(a[i]&a[j],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				for(int q=j+1;q<=n;q++)
					maxx=max(a[i]&a[j]&a[q],maxx);
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}