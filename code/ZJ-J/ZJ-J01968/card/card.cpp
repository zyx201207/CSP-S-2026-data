#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],f,b[200001],c[200001],d[200001],dd,ans,e,q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	    if(a[i]<a[i-1])f=1;
	}
	if(f==0){
		int k=1;
		for(int i=1;i<=n;i++){
		    if(a[i]!=k)k++;
		    b[k]++;
		}
		for(int i=1;i<=m;i++)
		    c[i]=c[i-1]+b[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i<=c[j])d[j]++;
			}
		}
	    for(int i=1;i<=m;i++)
	        cout<<d[i]<<" ";
	}
	else {
		if(m==1)cout<<n;
		else{
			if(a[n]==1)f=2;
			else f=1;
			if(a[n-1]!=f)ans=0;
			else for(int i=n;i>=1;i--){
			    if(a[i]==f){
				    dd=i;
				    ans=i;
				    e=f+1;
				}
				if(e==3)e=1;
			    if(dd!=0&&a[i]==e&&dd!=n-1&&q==0){
				    ans=n-i;
				    q=1;
				}
			}
			if(f==1)cout<<ans<<" "<<n;
			else cout<<n<<" "<<ans;
		}
		
	}
	return 0;
}
