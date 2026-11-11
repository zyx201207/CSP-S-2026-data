#include<bits/stdc++.h>
using namespace std;
struct N{
	int a;
	long long e;
}t[200005];
int f(int x){
	long long y=x,j=0;
	if(y%2==1){
		j++;
	}
	y=y/2;
	return j;
}
bool cmp(N a,N b){
	return a.e>b.e;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i].a;
		if(m==n&&t[i].a==0){
			cout<<0;
			return 0;
		}
		t[i].e=f(t[i].a);
	}
	if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((t[i].a&t[j].a)>maxn){
					maxn=t[i].a&t[j].a;
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==3){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if((t[i].a&t[j].a&t[k].a)>maxn){
						maxn=t[i].a&t[j].a&t[k].a;
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==4){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if((t[i].a&t[j].a&t[k].a&t[l].a)>maxn){
							maxn=t[i].a&t[j].a&t[k].a&t[l].a;
						}
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==5){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							if((t[i].a&t[j].a&t[k].a&t[l].a&t[r].a)>maxn){
								maxn=t[i].a&t[j].a&t[k].a&t[l].a&t[r].a;
							}
						}
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	sort(t+1,t+n+1,cmp);
	long long z=t[1].a;
	for(int i=2;i<=m;i++){
		z=z&t[i].a;
	}
	cout<<z;
	return 0;
}
