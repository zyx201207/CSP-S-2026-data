#include<iostream>
#include<cstring>
using namespace std;
int tc,t,n,f1[2000010],f2[2000010],fd1[2000010],fd2[2000010],dd1[2000010],dd2[2000010];
long long m,a[2000010],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>tc>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1,l=1;i<=n;i++){
			while(a[i]-a[l]>m)
				l++;
			f1[i]=l;
		}
		for(int i=n,l=n;i>=1;i--){
			while(a[l]-a[i]>m)
				l--;
			f2[i]=l;
		}
		memset(fd1+1,0,4*n);
		memset(fd2+1,0,4*n);
		memset(dd1+1,0,4*n);
		memset(dd2+1,0,4*n);
		for(int i=1;i<=n;i++){
			fd1[f2[i]]++;
			if(f1[f2[i]]==i)
				fd1[f2[i]]+=fd1[i];
			if(f2[i]-1>i){
				dd1[f2[i]]++;
				if(f1[f2[i]-1]==i)
					dd1[f2[i]]+=fd1[i];
			}
		}
		for(int i=n;i>=1;i--){
			fd2[f1[i]]++;
			if(f2[f1[i]]==i)
				fd2[f1[i]]+=fd2[i];
			if(f1[i]+1<i){
				dd2[f1[i]]++;
				if(f2[f1[i]+1]==i)
					dd2[f1[i]]+=fd2[i];
			}
		}
		d=0;
		for(int i=1;i<n;i++)
			d+=1ll*dd2[i]*dd1[i+1];
		cout<<d<<'\n';
	}
}
