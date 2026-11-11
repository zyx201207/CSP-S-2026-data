#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],an[500010],ch[500010],s[500010];
bool b(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	cout<<1;
	sort(a+1,a+n+1,b);
//	cout<<1;
	for(int i=1;i<=n;i++){
//		cout<<1;
		ch[i]=a[i]-a[i-1];
		ch[1]=0;
		s[i]=s[i-1]+ch[i];
//		cout<<ch[i]<<" "<<s[i]<<"\n";
	}
	ch[1]=0;
	int c=0,mx=0;int j=0;
	for(int i=1;i<=n;i++){
		int x=0;
		an[i]=an[i-1]+1;
		c+=an[i-1]*ch[i];
		while(c>m){
//			cout<<c<<" ";
			j++;
			an[i]-=1;
			c-=s[i]-s[j];
//			cout<<s[j]<<"\n";
		}
		
		mx=max(mx,an[i]);
	}
	cout<<mx;
//	for(int i=1;i<=n;i++){
//		cout<<"\n"<<an[i]<<" "<<a[i];
//	}
	return 0;
}
