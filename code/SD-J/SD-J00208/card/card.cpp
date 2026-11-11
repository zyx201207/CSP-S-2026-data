#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5+5;
long long n,m;
int a[N],b[N],c[N],d[N],bn=1;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(b[i]==b[i-1]) continue;
		d[i]=b[i];
	}
	sort(d+1,d+1+n,cmp);
	for(int i=1;i<=n;i++){
		int f[N],fn=0;
		//f[1]=a[1];
		for(int j=i;j<=n;j++){
			int b=0;
			for(int k=1;k<=fn;k++) if(f[k]==a[j]) b=k;
			if(b!=0) fn=b-1;
			fn++;
			f[fn]=a[j];
//			cout<<fn<<'/';
//			for(int k=0;k<=fn;k++){
//				cout<<f[k]<<' ';
//			}
//			cout<<endl;
		}
		for(int j=1;j<=fn;j++){
//			cout<<f[j]<<' ';
			c[f[j]]++;
		}
//		cout<<endl;
	}
	for(int i=m;i>=1;i--) cout<<c[d[i]]<<' ';
	return 0;
}
