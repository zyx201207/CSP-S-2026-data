#include<bits/stdc++.h>
using namespace std;
int t,m,a[500005],ans[300005]={0},bj[300005]={0},mn[500005],f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>t>>m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
		bj[a[i]]=max(bj[a[i]],i);
		if(a[i]<a[i-1])f=0;
	}if(f==1){
		for(int i=1;i<=m;i++)cout<<bj[i]<<" ";
		return 0;
	}for(int i=1;i<=t;i++){
		if(m<=2&&t>500){
			if(a[i]+a[t]==3)ans[1]++,ans[2]++;
			else ans[a[t]]++;
		}else{
			for(int j=1;j<=t;j++)mn[i]=0;
			int r=1;
			for(int j=i;j<=t;j++){
				int f2=0,f3=0;
				for(int k=1;k<=r;k++)if(mn[k]==a[j])f2=1;
				if(f2==1){
					while(f3==0){
						if(mn[r]==a[j])f3=1;
						r--;
					}
				}r++,mn[r]=a[j];
			}for(int j=1;j<=r;j++)ans[mn[j]]++;
		}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
