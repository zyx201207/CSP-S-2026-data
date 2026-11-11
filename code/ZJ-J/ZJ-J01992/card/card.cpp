#include<bits/stdc++.h>
using namespace std;
int a[500005],z[300005],p,cnt[300005];
void d(int x){
	bool d=0;
	for(int i=1;i<=p;i++){
		if(d==0){
			if(z[i]==x){
				d=1,z[i]=0;
				continue;
			}
		}
		else z[i]=0,p--;	
	}
	if(d==1) p--;
	z[++p]=x;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1]) b=1;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]){
				cnt[a[i]]++;
			}
			else cnt[a[i]]++,cnt[a[n]]++;
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
		return 0;
	}
	if(b==1){
		for(int i=1;i<=n;i++){	
			p=0;
			for(int j=1;j<=m;j++) z[j]=0;
			for(int j=i;j<=n;j++) d(a[j]);
			for(int j=1;j<=p;j++) cnt[z[j]]++;
		}
	}
	else{
		int o=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]) o++;
			for(int j=o;j<=m;j++){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}