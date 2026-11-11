#include<bits/stdc++.h>
using namespace std;
int a[1000010];
char c[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long le=0;
	long long ri=0;
	for(int i=1;i<=n/2;i++){
		le+=a[i];
		ri+=a[n-i+1];
	}
	bool single=true;
	for(int i=1;i<=n;i++){
		if(c[i]!=c[1]){
			single=false;
		}
	}
	if(single){
		cout<<0;
		return 0;
	}
	bool flag=true;
	if(!single){
		for(int i=1;i<=n/2;i++){
			if(a[i]!=a[n+1-i]||c[i]!=c[n+1-i]){
				flag=false;
				break;
			}
		}
	}
	if(flag){
		cout<<0;
	}else{
		long long right=n;
		long long minc=0;
		long long gh=0;
		for(int i=1;i<=n/2;i++){
			if(a[i]>=a[right]){
				if(c[i]!=c[right]){
					if(a[i]>a[right]&&a[i]<=sum/2){
						gh=a[right];
						int d=right-1;
						while(gh<a[i]){
							if(c[d]!=c[i]){
								gh+=a[d];
							}
							d-=1;
						}
						if(gh>=ceil(1.0*sum/2)){
							gh=ceil(1.0*sum/2)-a[d];
						}
						minc+=gh;
						right=d;
						if(i==right){
							break;
						}
					}else if(a[i]>sum/2){
						for(int j=i+1;j<=n;j++){
							if(c[j]!=c[i]){
								minc+=a[j];
							}
						}
						if(i>1){
							for(int j=1;j<=i;j++){
								if(c[j]!=c[i]){
									minc+=a[j];
								}
							}
						}
						cout<<minc;
						return 0;
					}else if(a[i]==a[right]){
						minc+=a[i];
					}else if(a[i]<a[right]){
						gh=a[i];
						int d=i+1;
						while(gh<a[right]){
							if(c[d]!=c[right]){
								gh+=a[d];
							}
							d+=1;
						}
						minc+=gh;
						i=d;
						if(i==right){
							break;
						}
					}
				}
			}
		}
		if(n%2==1&&le!=ri){
			int m=ceil(n/2);
			minc+=a[m]-1;;
		}
		cout<<minc;
	}
	return 0;
}
