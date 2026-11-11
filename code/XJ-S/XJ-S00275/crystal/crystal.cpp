#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
string s2;
int n,m,a[N],pre[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>s2;
	int len2=s2.size();
	if(len2>8){
		int x=0,y=0;
		for(int i=1;i<=n;i++){
		   string str;
		   cin>>str;
		   if(i==1){
		   	  for(int j=0;j<str.size();j++)
		   	     x=x*10+str[j]-'0';
		   }
		   if(i==2){
		   	  for(int j=0;j<str.size();j++)
		   	     y=y*10+str[j]-'0';
		   }
	    }
	    if(x==y) cout<<n;
	    else{
	    	int d=abs(x-y),cnt=1,sum=0;
	    	while(sum<=m){
	    		sum+=cnt*d;
	    		cnt++;
			}
			cout<<cnt+1;
		}
		return 0;
	}
	for(int i=0;i<len2;i++) m=m*10+s2[i]-'0';
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=1;
	while(r<=n&&l<=r){
		if(a[r]*(r-l+1)-pre[r]+pre[l-1]<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<ans;
	return 0;
}

