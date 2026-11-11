#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000010],sum[1000010];
int s[1000010],t,ans[1000010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(sum[a[j]]>0){
				//cout<<"start:\n";
				while(s[t]!=a[j]){
					sum[s[t]]--;
					//cout<<t<<" "<<s[t]<<"!!!\n";
					t--;
				}sum[a[j]]--;
				//cout<<t<<" "<<a[j]<<"!!!\n";
				t--;
				//cout<<"end<<\n";
			}sum[a[j]]++;
			s[++t]=a[j];
			//cout<<"+"<<a[j]<<"\n";
		}//cout<<"end"<<i<<":\n";
		for(int i=1;i<=m;i++){
			ans[i]+=sum[i];
			sum[i]=0;
			//cout<<ans[i]<<" ";
		}//cout<<"\n";
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}
