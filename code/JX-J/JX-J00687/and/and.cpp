#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],maxn=0,maxnn=0;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	int ans1=a[1],ans2=0;
	for(int i=2;i<=n;i++){
		ans1=(ans1&a[i]);
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			ans2=max(ans2,(a[i]&a[j]));
		}
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==2){
		cout<<ans2;
		return 0;
	}
	else if(m==n){
		cout<<ans1;
		return 0;
	}
	else if(m==n-1){
		long long ans3=0;
		for(int i=1;i<=n;i++){
			if(i==1){
				long long x=a[2];
				for(int j=3;j<=n;j++){
					x=x&a[j];
				}
				ans3=max(ans3,x);
				continue;
			}
			long long x=a[1];
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				x=x&a[j];
			}
			ans3=max(ans3,x);
		}
		cout<<ans3;
		return 0;
	}
	else if(m==3&&n<=200){
		int maxn1=0;
		for(int i1=1;i1<=n-2;i1++){
			for(int i2=i1+1;i2<=n-1;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					maxn1=max(maxn1,((a[i1]&a[i2])&a[i3]));
				}
			}
		}
		cout<<maxn1;
		return 0;
	}
	else if(m==4&&n<=50){
		int maxn2=0;
		for(int i0=1;i0<=n-3;i0++){
			for(int i1=i0+1;i1<=n-2;i1++){
				for(int i2=i1+1;i2<=n-1;i2++){
					for(int i3=i2+1;i3<=n;i3++){
						maxn2=max(maxn2,((a[i1]&a[i2])&(a[i3]&a[i0])));
					}
				}
			}
		}
		cout<<maxn2;
		return 0;
	}
	else if(m==5&&n<=20){
		int maxn2=0;
		for(int j=1;j<=n-4;j++){
			for(int i0=j+1;i0<=n-3;i0++){
				for(int i1=i0+1;i1<=n-2;i1++){
					for(int i2=i1+1;i2<=n-1;i2++){
						for(int i3=i2+1;i3<=n;i3++){
							maxn2=max(maxn2,((a[i1]&a[i2])&((a[i3]&a[i0])&a[j])));
						}
					}
				}
			}

		}
		cout<<maxn2;
		return 0;
	}
	else if(m==6&&n<=20){
		int maxn2=0;
		for(int j0=1;j0<=n-5;j0++){
			for(int j=j0+1;j<=n-4;j++){
				for(int i0=j+1;i0<=n-3;i0++){
					for(int i1=i0+1;i1<=n-2;i1++){
						for(int i2=i1+1;i2<=n-1;i2++){
							for(int i3=i2+1;i3<=n;i3++){
								maxn2=max(maxn2,((a[i1]&a[i2])&((a[i3]&a[i0])&a[j])));
							}
						}
					}
				}

			}

		}
		cout<<maxn2;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
    return 0;
}
