#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],c[N],f[N];
bool b[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
memset(b,0,sizeof(b));
memset(d,0,sizeof(d));
memset(f,0,sizeof(f));
for(int j=i;j<=n;j++){
	if(b[a[j]]==0){
	b[a[j]]=1;
	f[a[j]]=j;}
	else{
		for(int z=f[a[j]]+1;z<=j;z++){
			if(d[z])continue;
//			cout<<z<<" ";
			b[a[z]]=f[a[z]]=0;
			d[z]=1;
		}
//		cout<<endl;
		f[a[j]]=j;
		b[a[j]]=1;
	}
}
for(int j=1;j<=m;j++){
//	cout<<b[j]<<" ";
	if(b[j])c[j]++;
}
//cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}//	for(int j=n;j>=1;j--)
//	if(a[j]==i){
//		cout<<j<<" ";
//		break;
//	}
