#include<bits/stdc++.h>
using namespace std;
int n,m,ans;  
int a[10001],b[10001][2],a1[10001];	
int t=m;
int fs(int i,int j){
	t-=j;
	a1[i]+=j;
	if(t<=0){
		sort(a1+1,a1+n+1);
		int q=1;
		for(int e=1;e<=n;e++){
			bool tu=1;
			int f=1;
			for(f;f<q;f++){
				if(a1[f]==b[f][1]){
					b[f][2]++;
					tu=0;
					break;
				}
			}
			if(tu==1){
				b[f][1]=a1[f];
				b[f][2]++;
				q++;
			}	
		}
		int y=0,z2;
		for(int e=1;e<=n;e++){
			if(b[e][2]>y){
				y=b[e][2];
				z2=i;
			}		
		}
		ans=y;
		for(int e=1;e<=n;e++) a1[e]=a[e];
		for(int e=1;e<=n;e++){
			b[e][1]=0;
			b[e][2]=0;
		}
		t=m;
		return ans;
	}
	for(int q=0;q<=t;q++)ans=max(fs(i+1,q),ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int e=1;e<=n;e++) a1[e]=a[e];
	sort(a1+1,a1+n+1);
	for(int i=1;i<=n;i++) for(int j=m;j>=1;j--) fs(i,m);
	cout<<ans;
	return 0;
}