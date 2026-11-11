#include<bits/stdc++.h>
using namespace std;
int a[200005],max_l,l[200005];
bool c[200005][32];
bool fff[200005][35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}//ÌØÅÐ 
	for(int i=1;i<=n;i++){
		int s=a[i];
		int t=1;
		while(s!=0){
			c[i][t]=s%2;
			s=s/2;
			t++;
		}
		l[i]=t-1;
		max_l=max(max_l,l[i]);
	}//µ¹ÐòµÄ2Î¬ 
	for(;max_l>=1;max_l--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(l[j]>=max_l&&c[j][max_l]==1){
				sum++;
			}
		}
		if(sum>=m){
			break;
		}
	}//¶Ô 
//	cout<<max_l<<endl;
	if(max_l==0){
		cout<<0;
	}else{
		int zl=0;
		bool du[35];
		for(int j=1;j<=n;j++){
			if(l[j]>=max_l&&c[j][max_l]==1){
				zl++;
				for(int O=1;O<=max_l;O++){
					fff[zl][O]=c[j][O];
				}
			}
			fff[j][33]=1;
		}
		for(int i=max_l;i>=1;i--){
			int sum=0;
			for(int j=1;j<=zl;j++){
				if(fff[j][33]==1&&fff[j][i]==1){
					sum++;
				}
			}
			if(sum>=m){
				for(int j=1;j<=zl;j++){
					if(fff[j][i]!=1){
						fff[j][33]=0;
					}
				}
				du[i]=1;
			}else{
				du[i]=0;
			}
		}
//		for(int j=1;j<=zl;j++){
//		cout<<fff[j][33]<<":";
//			for(int i=max_l;i>=1;i--){
//				cout<<fff[j][i]; 
//			}
//			cout<<endl;
//		}//²âÊÔ 
		int ans=0;
		for(int i=max_l;i>=1;i--){
//			cout<<du[i];
			ans=ans*2+du[i];
		}
//		cout<<endl;
		cout<<ans;
	}
	return 0;
}
