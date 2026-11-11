#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxai=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxai=max(maxai,a[i]);
	}
	int ans=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==3){
		for(int i1=1;i1<=n-3;i1++){
			for(int i2=i1+1;i2<=n-2;i2++){
				for(int i3=i2+1;i3<=n-1;i3++){
						ans=max(ans,a[i1]&a[i2]&a[i3]);
				}
			}
		}
	}else if(m==4){
		for(int i1=1;i1<=n-3;i1++){
			for(int i2=i1+1;i2<=n-2;i2++){
				for(int i3=i2+1;i3<=n-1;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]);
					}
				}
			}
		}
	}else if(m==5){
		for(int i1=1;i1<=n-4;i1++){
			for(int i2=i1+1;i2<=n-3;i2++){
				for(int i3=i2+1;i3<=n-2;i3++){
					for(int i4=i3+1;i4<=n-1;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]);
						}
					}
				}
			}
		}
	}
	if(m==6){
		for(int i1=1;i1<=n-5;i1++){
			for(int i2=i1+1;i2<=n-4;i2++){
				for(int i3=i2+1;i3<=n-3;i3++){
					for(int i4=i3+1;i4<=n-2;i4++){
						for(int i5=i4+1;i5<=n-1;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]);
							}
						}
					}
				}
			}
		}
	}
	if(m==7){
		for(int i1=1;i1<=n-5;i1++){
			for(int i2=i1+1;i2<=n-4;i2++){
				for(int i3=i2+1;i3<=n-3;i3++){
					for(int i4=i3+1;i4<=n-2;i4++){
						for(int i5=i4+1;i5<=n-1;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									ans=max(ans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]);
								}
							}
						}
					}
				}
			}
		}
	}
	if(maxai==1){
		long long minai=5;
		for(int i=1;i<=n;i++){
			if(minai>a[i]) minai=a[i];
		}
		if(maxai==1){
			if(minai==0){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<ans;
	}
	return 0;
}

