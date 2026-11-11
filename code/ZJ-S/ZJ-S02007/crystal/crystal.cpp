#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,k=0,l=0;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]==l){
			k++;
		}
	}
	if(k==n-1){
		long long x=0,y=0;
		while(m>=x){
			m-=x;
			x+=(l*2);
			y++;
		}
		if(m==0){
			cout<<y*2-1;
		}else{
			if(m>=x/2) cout<<y*2;
			else cout<<y*2-1;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			b[j]=abs(a[i]-a[j]);
		}
		sort(b+1,b+1+n);
		long long M=m;
		for(long long j=1;j<=i;j++){
			M-=b[j];
			if(M==0){
				ans=max(ans,j);
			}
			else if(M<0){
				ans=max(ans,j-1);
				break;
			}else if(j==i){
				ans=max(ans,i);
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}