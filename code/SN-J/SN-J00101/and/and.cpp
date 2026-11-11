#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[500005],s[500005],t[300005],k,cnt=1,ans,f=1,l,v[500005],o,b[500005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("add.in","r",stdin);
//	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
}
s[0]=1;
for(int i=1;i<=31;i++){
	s[i]=s[i-1]*2;
}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=31;j>=1;j--){
			if(s[j]<a[i]&&a[i]<s[j+1]){
			t[j]++;
			break;
			}
		}
	}
	for(int i=31;i>=1;i--){
		v[i]=v[i-1]+t[i];
	}
	for(int i=31;i>=1;i--){
	cnt+=t[i];
		if(t[i]>=m){
		k=i;
		break;
		}
	}
	//cout<<l<<" "<<k;
	for(int i=31;i>=k;i--){
		if(v[i]<m)
		continue;
		memset(b,0,sizeof(b));
		for(int j=1;j<=v[i];j++)
		b[j]=a[j]%s[i];
		sort(b+1,b+v[i]+1,cmp);
		unsigned long long g=b[1];
		for(int j=1;j<=m;j++){
			g=g&b[j];
			//cout<<b[j]<<" ";
		}
		//cout<<endl;
		ans=max(ans,g);
	}
	cout<<ans;
	return 0;
}
