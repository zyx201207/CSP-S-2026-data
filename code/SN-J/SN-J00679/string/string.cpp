//zuoxianke 西安铁一中学 SN-J00679
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int l[200005],r[200005];
int l1[200005],r1[200005];
int l2[200005],r2[200005];
char c[200001],c2[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		l[i]=r[i-1]+1;
		int x;
		cin>>x>>c[i];
		sum+=x;
		r[i]=r[i-1]+x;
//		cout<<l[i]<<' '<<r[i]<<endl;
	}
//	cout<<endl; 
	for(int i=1;i<=n;i++){
		l1[i]=sum-l[i]+1;
		r1[i]=sum-r[i]+1;
		c2[i]=c[n-i+1];
		swap(l1[i],r1[i]);
	}
	for(int i=1;i<=n;i++){
		l2[i]=l1[n-i+1];
		r2[i]=r1[n-i+1];
//		cout<<l2[i]<<' '<<r2[i]<<endl;
	}
	int i=1,j=1,x=1,ans=0;
	while((i<n||j<n)&&x<=sum/2){
		int y=min(r[i],r2[j]);
//		cout<<x<<' '<<ans<<endl;
		if(c[i]!=c2[j]){
			ans+=y-x+1;
//			if(r[i]>r[i])c2[j]=c[i];
//			else c[i]=c2[j];
		}
		x=y+1;
		if(r[i]>r2[j])j++;
		else i++;
	}
	cout<<ans;
}
