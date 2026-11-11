#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,p[200005],ans,ans1;
bool b[200005];
void dg(int m1,int n1){
	p[m1]++;
	if(p[m1]>=n1){
		dg(m1-1,n1-1);
		p[m1]=p[m1-1]+1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
    	p[i]=i;
	}
	p[m]--;
	while(1){
		ans1=a[p[0]];
		for(int i=0;i<m;i++) ans1&=a[p[i]];
		ans=max(ans,ans1);
		if(p[0]>=n-m){
			break;
		}
		dg(m-1,n);
	}cout<<ans<<endl;
	return 0;
}
