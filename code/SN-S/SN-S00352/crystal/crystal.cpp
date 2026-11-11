//刘泰豫 SN-S00352 西安市第一中学
#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,b[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}for(int i=0;i<n;i++){
		long long m1=m,ans1=1,b1=0;
		for(int j=i;j<n;j++){
			if(b[j]==0){
				ans1++;
				ans=max(ans,ans1-1);
				continue;
			}b1+=b[j];
			if(m1-b1>=0){
				m1-=b1;
				ans1++;
			}else{
				ans=max(ans,ans1);
				break;
			}
		}
	}cout<<ans;
	return 0;
}
