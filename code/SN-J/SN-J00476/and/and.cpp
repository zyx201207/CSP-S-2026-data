#include<bits/stdc++.h>
using namespace std;
int a[200005],b[100005],c[100005],cnt1=0,cnt=0;
int n,m;
//struct Tree
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++)b[i]=a[i];cnt=n;
	int ans=0;
	for(int i=30;i>=1;i--){
		cnt1=0;
		for(int j=1;j<=cnt;j++){
			if(b[j]&(1<<(i-1)))c[++cnt1]=b[j];
		}
	//	cout<<i<<" "<<cnt1<<endl;
		if(cnt1>=m){
			ans+=(1<<(i-1));
			for(int j=1;j<=cnt1;j++)b[j]=c[j];
			cnt=cnt1;
		}
	}
//	int ans=a[1];
//	for(int i=1;i<=m;i++)ans=(ans&a[i]);
	cout<<ans<<endl;
}

