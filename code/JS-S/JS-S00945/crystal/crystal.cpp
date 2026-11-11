#include<bits/stdc++.h>
using namespace std;
long long m,n,a[100005],ea;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=2;i<=n;i++){
			long long ans=0,mn=m,j=i;
			for(int l;mn>=0;j--){
				l++;
				if(j<=0)break;
				mn-=a[i]-a[j];
				ans++;
				
			}
			if(mn<0)ans--;
		
			ea=max(ans,ea);
		
		}
		cout<<ea;
		
	}else{
		
		long long ans=0;
		for(int i=1;m>=0;i+=a[2]-a[1]){
			m-=i;
			ans++;
		}
		if(m<0)ans--;
		cout<<ans;
		
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
