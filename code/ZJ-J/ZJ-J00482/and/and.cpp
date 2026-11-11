#include<bits/stdc++.h>
using namespace std;
long long a[200005],ma,x[200005][35],cnt;
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long t=a[i],w=1;
		while(t!=0){
			x[i][w]=t%2;
			t=t/2;
			w++;
		}
		ma=max(ma,w-1);
	}
	ma++;
	while(ma--){
		long long t=0;
		for(int i=1;i<=n;i++){
			if(x[i][ma]==1&&a[i]!=-1) t++;
		}
		if(t>=m){
			for(int i=1;i<=n;i++){
				if(x[i][ma]==0){
					a[i]=-1;
				}
			}
		}
	}
	long long t;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			cnt=a[i];
			t=i;
			break;
		}
	}
	long long w=1;
	for(int i=t+1;w<=m&&i<=n;i++){
		if(a[i]!=-1){
			w++;
			cnt=cnt&a[i];
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
