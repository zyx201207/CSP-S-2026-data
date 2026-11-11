#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500006];
long long len,ans=0,ye;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ye=m;
    len=1;
    for(int i=2;i<=n;i++){
    //	cout<<ye<<" ";
    	if((a[i]-a[i-1])*len<=ye){
    		len++,ye-=(a[i]-a[i-1])*(len-1);
    		ans=max(ans,len);
		}
		else{
			long long q=(a[i]-a[i-1])*len;
			//cout<<q<<' ';
			int zt=0;
			for(int j=i-len;j<i;j++){
				zt++;
				ye+=(a[i-1]-a[j]),q-=(a[i]-a[i-1]);
				if(ye>=q){
					ye-=q;
					break;
				}
			}
			len-=(zt-1);
		}
		//cout<<len<<" "<<ye<<' ';
	}
	cout<<ans; 
}