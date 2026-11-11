#include<bits/stdc++.h>
using namespace std;
int n,ans=1,stay=1,i=2;
long long a[500001],m,len;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	len=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	while(i<=n){
		if((a[i]-a[i-1])*(i-stay)>len){
		    ans=max(ans,i-stay);
		    while((a[i]-a[i-1])*(i-stay)>len){
		    	len+=a[i-1]-a[stay];
		    	stay++;
			}
			len-=(a[i]-a[i-1])*(i-stay);
			i++;
	    }
	    else{
	    	len-=(a[i]-a[i-1])*(i-stay);
	    	i++;
	    	ans=max(ans,i-stay);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
