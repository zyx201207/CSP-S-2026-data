#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	long long x[n];
	char y[n];
	for(long long i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}long long a=0,b=n-1;
	for(long long i=0;i<n;i++){
		if(a>=b){
			cout<<ans;
			return 0;
		}
		if(x[a]==x[b]){
			if(y[a]!=y[b]){
				ans+=x[a];
				a++;b--;
			}else{
				a++;b--;
			}
		}else{
			if(y[a]==y[b]){
				if(x[a]>x[b]){
					x[a]-=x[b];
					b--;
				}else{
					x[b]-=x[a];
					a++;
				}
			}else{
				if(x[a]>x[b]){
					ans+=x[b];
					x[a]-=x[b];
					b--;
				}else{
					ans+=x[a];
					x[b]-=x[a];
					a++;
				}
			}
		}
	}cout<<ans;
	return 0;
}
