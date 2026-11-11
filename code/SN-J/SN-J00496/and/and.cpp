#include<bits/stdc++.h>
using namespace std;
int q[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,z=0,ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		int e=0,r=0;
		while(q[i]){
			e=e*10+q[i]%2;
			q[i]=q[i]/2;
		}
		while(e){
			r=r*10+r%10;
			e=e/10;
		}
		q[i]=r;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			z=0;			
			for(int k=1;k<=min(q[i],q[i+j]);k++){
				int p=k-1,o=1;
				if(k!=1) o*=2;
				if(q[i]%10==q[i+j]%10) z+=o;
			}
			ans=max(ans,z);
		}
	}
	cout<<ans;
	return 0;
}
