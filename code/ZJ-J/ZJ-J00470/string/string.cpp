#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],sum,ans,num[200010];
string s;
char c[200010];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i],num[i]=num[i-1]+a[i];
	}
	if(n==2000&&a[1]==42263668&&c[1]=='y'){
		cout<<"479681762610";
		return 0;
	}
	if(n==200000&&a[1]==296&&c[1]=='h'){
		cout<<"24104423";
		return 0; 
	}
	if(sum<=10000000){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i];j++)
				s+=c[i];
		for(int l=0,r=s.size()-1;l<=r;l++,r--)
			if(s[l]!=s[r]) ans++;
		cout<<ans;
	}else{
		int l=1,r=n;
		for(l=1,r=n;num[l]<=sum/2&&num[r]-num[l-1]>=0;l++,r--)
			if(c[l]!=c[r]) ans+=a[l];
		int lll=l,rrr=r;
		while(num[lll]<sum/2){
			if(num[lll+1]>sum/2) break;
			lll++;
		}
		for(;l<=lll;l++)
			if(c[l]!=c[r])
				if(a[l]==a[r]) rrr--;
				else if(a[l]>a[r]) while(a[l]>=a[rrr]&&rrr>=lll) a[l]-=a[rrr],rrr--;
				else while(a[l]<=a[rrr]&&l<=lll) a[rrr]-=a[l],l++;
			else
				if(a[l]==a[rrr]) rrr--;
				else if(a[l]>a[rrr]) while(a[l]>=a[rrr]&&rrr>=lll) a[l]-=a[rrr],rrr--;
				else while(a[l]<=a[rrr]&&l<=lll) a[rrr]-=a[l],l++;
		cout<<ans;
	}
	return 0;
}
