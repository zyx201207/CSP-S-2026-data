#include<bits/stdc++.h>
using namespace std;
long long l,r,a[200005],le,b[200003],mi,ans,li,ri;
int n;
char c[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		le+=a[i];
		b[i]=b[i-1]+a[i];
	}
	mi=le/2+1;
	for(int i=1;i<=n;i++){
		if(mi>b[i-1]&&mi<=b[i]){
			l=max(b[i-1]+1,mi-(b[i]-mi));
			r=mi+(mi-l);
			li=ri=i;
			break;
		}
	}
	while(l>1||r<le){
		long long t,lt,rt;
		lt=(li==1?1e18:b[li-1]+1-b[li-2]-1);
		rt=(ri==n?1e18:b[ri+1]-b[ri]);
		t=min(lt,rt);
		if(l==b[li-1]+1&&r==b[ri]){
			li--;
			ri++;
		}else if(l==b[li-1]+1){
			li--;
		}else{
			ri++;
		}
		if(c[li]!=c[ri])ans+=t;
		l-=t;
		r+=t;
	}
	cout<<ans;
	return 0;
}
