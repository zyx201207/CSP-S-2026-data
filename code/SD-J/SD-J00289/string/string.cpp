#include<bits/stdc++.h>
#define int long long
using namespace std;
long long lens[200010],a[200010];
char c[200010];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	long long len=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		lens[i]=lens[i-1]+a[i];
	}
	int mid=lower_bound(lens+1,lens+n+1,len/2)-lens,r=n;
	for(int i=1;r>mid+len%2&&i<=mid;i++){
		int num=r;
		if(lens[n]-lens[num-1]==lens[i]){
			if(c[i]!=c[num])ans+=a[i];
			num--;
			continue;
		}else if(lens[n]-lens[num-1]<lens[i]){
			if(c[num]!=c[i])ans+=lens[n]-lens[num-1]-lens[i-1];
			while(num>mid+len%2&&lens[n]-lens[num-1]<lens[i]){
				if(c[num-1]!=c[i])ans+=lens[i]-lens[n]+lens[num-1];
				num--;
			}
			if(num>mid+len%2&&lens[n]-lens[num-1]>lens[i]){
				if(c[i]!=c[num])ans+=lens[n]-lens[num-1]-lens[i];
			}
		}else if(lens[n]-lens[num-1]>lens[i]){
			if(c[i]!=c[num])ans+=a[i];
		}
		r=num;
	}
	cout<<ans<<'\n';
	return 0;
} 
