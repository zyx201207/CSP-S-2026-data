#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2000010],sum,ans;
char s[2000010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>s[i];
		sum+=a[i];
		if(s[i]==s[i-1]){
			n--;
			a[i-1]+=a[i];
			i--;
			
		}
		
	}
	int p=1,q=n;
	while(p<q){
		if(s[p]!=s[q]){
			//cout<<a[p]<<" "<<a[q]<<endl<<ans<<endl;
			if(a[p]>a[q]){
				ans+=a[q];
				a[p]-=a[q];
				q--;
				
			}
			else{
				ans+=a[p];
				a[q]-=a[p];
				p++;
								
			}
		}
		else{
			if(a[p]>a[q]){
				//ans+=a[q];
				a[p]-=a[q];
				q--;
				
			}
			else{
				//ans+=a[p];
				a[q]-=a[p];
				p++;
								
			}			
		}
	}
	 
	cout<<ans;
	return 0;
}

