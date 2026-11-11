#include<bits/stdc++.h>
using namespace std;

long long n,ans;
long long m1,m2,f[500010],a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m1;
	for(int i=0;i<n;i++) cin>>f[i];
	sort(f,f+n);
	for(int j=0;j<=n/2;j++){
		m2=m1;
		for(int i=0;i<n;i++) a[i]=f[i];
		long long x=j,b=1;
		while(m2>=0){
			if(a[x]==a[x+1]){
				int c=0;
				for(int i=1;i<=n;i++){
					if(a[x+i]==a[x]){
						c++;	
					}
				}
				x+=c,b+=c;
			}
			a[x]++;
			m2-=b;
		}	
		ans=max(ans,b);	
	}

	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
