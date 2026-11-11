#include<bits/stdc++.h>
using namespace std;
const long long  M=1e5+10;
string s[2*M];
long long a[2*M];
long long n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i]>>s[i];
	for(int l=1;l<=n;l++){
		int r=n-l+1;
		if(l>=r) break;
		if(s[l]!=s[r]) {
			             if(a[l]<=a[r]) {
			             	              ans+=a[r];
			             	              s[r]=s[l];
						                }
			             if(a[l]>a[r])  {
			             	              ans+=a[l];
			             	              int h=a[l],cnt=0;
			             	              while(h>0){
			             	              	if(h-a[r-cnt]>0){
			             	              		h-=a[r-cnt];
			             	              		s[r-cnt]=s[l];
											   }
											else{
												a[r-cnt]-=h;
												a[r-cnt+1]+=h;
												h=0;
											  }
											cnt++;
										   }
						                }     
		               }
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
