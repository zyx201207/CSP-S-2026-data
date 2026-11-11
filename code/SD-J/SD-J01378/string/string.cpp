#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200009],b[200009],c[400009],d[400009],e[400009],cnt,l,ans,res;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		b[i]=c-'a';
		l+=a[i];
	}
	
	if(l%2==1){
		for(int i=1,j=0;i<=n;i++){
			j+=a[i];
			if(j>l/2){
				if(a[i]==1){
					for(int k=i;k<n;k++) a[i]=a[i+1],b[i]=b[i+1];
					n--;
					break;
				}
				a[i]--;
				break;
			}
		}
		l--;
	}//cout<<l<<'\n';
	for(int i=1,j=0;i<=n;i++){
		j+=a[i];
		c[++res]=j;
		c[++res]=l-j;
		//cout<<j<<' '<<l-j<<'\n';
	}
	
	sort(c+1,c+res+1);
	res=unique(c+1,c+res+1)-c-1;
	//for(int i=1;i<=res;i++) cout<<c[i]<<'\n';
	//cout<<res<<'\n';
	for(int i=1,j=1,ii=0,jj=0;i<=res;i++,j++){
		jj+=a[j];
		ii=c[i];
		d[++cnt]=c[i]-c[i-1],e[cnt]=b[j];
		//cout<<ii<<' '<<jj<<'\n';
		while(ii<jj){
			i++,ii=c[i];
			d[++cnt]=c[i]-c[i-1],e[cnt]=b[j];
		}
	}
	if(d[1]==0){
		for(int i=1;i<cnt;i++) d[i]=d[i+1],e[i]=e[i+1];
		cnt--;
	}
	//cout<<cnt<<'\n';
	//for(int i=1;i<=cnt;i++) cout<<d[i]<<' '<<e[i]<<'\n';
	for(int i=1;i<=cnt/2;i++){
		if(e[i]!=e[cnt-i+1]) ans+=d[i];
	}
	cout<<ans;
	
	
	
	
	return 0;
}
/*
³æÐè
ÔÆÁ¦
°×É×
³æÇÒ 
*/ 
