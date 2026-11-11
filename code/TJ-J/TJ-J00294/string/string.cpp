#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001];
char b[200001];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
    }
	int j=1;
	for(int i=n;i>n/2;--i){
		if(!a[i]) continue;
		if((n%2)&&(i==n/2+1)) break;
		if(j>=i) break;
		if(a[i]==a[j]&&b[i]!=b[j]) ans+=a[i];
		if(a[i]!=a[j]&&b[i]==b[j]){
			if(a[i]>a[j]){
				int cnt=1;
				for(int k=j+1;k<i;++k){
					++cnt;
					a[j]+=a[k];
					if(b[k]!=b[j]) ans+=a[k];
					if(a[i]<=a[j]){
						if(b[k]!=b[j]){
							ans-=a[k];
							ans+=a[j]-a[i];
						}
						a[k]-=a[j]-a[i];
						if(a[k]!=0) --cnt;
						break;
					}
				}
				j+=cnt;
			}else{
				for(int k=i-1;k>j;--k){
					a[i]+=a[k];
					if(b[k]!=b[j]) ans+=a[k];
					if(a[i]>=a[j]){
						if(b[k]!=b[j]){
							ans-=a[k];
							ans+=a[i]-a[j];
						}
						a[k]-=a[i]-a[j];
						break;
					}
				}
			}
		}
		if(a[i]!=a[j]&&b[i]!=b[j]){
			if(a[i]>a[j]){
				int cnt=1;
				ans+=a[j];
				for(int k=j+1;k<i;++k){
			        ++cnt;
					a[j]+=a[k];
					if(b[k]!=b[j]) ans+=a[k];
					if(a[i]<=a[j]){
						if(b[k]!=b[j]){
							ans-=a[k];
							ans+=a[j]-a[i];
						}
						a[k]-=a[j]-a[i];
						if(a[k]!=0) --cnt;
						break;
					}
				}
				j+=cnt;
			}else{
				ans+=a[i];
				for(int k=i-1;k>j;--k){
					a[i]+=a[k];
					if(b[k]!=b[j]) ans+=a[k];
					if(a[i]>=a[j]){
						if(b[k]!=b[j]){
							ans-=a[k];
							ans+=a[i]-a[j];
						}
						a[k]-=a[i]-a[j];
						break;
					}
				}
			}
		}
		++j;
	}
	cout<<ans;
	return 0;
}
