#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ma;
bool f=false;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}else if(m==n){
		ma=a[1];
		for(int i=2;i<=n;i++){
			ma=ma&a[i];
		}
		cout<<ma;
		return 0;
	}else{
		if(m==3){
			for(int i=1;i<=n-2;i++)
				for(int j=i+1;j<=n-1;j++)
					for(int k=j+1;k<=n;k++)
						ma=max(ma,a[i]&a[j]&a[k]);
		}else if(m==4){
			for(int i=1;i<=n-3;i++)
				for(int j=i+1;j<=n-2;j++)
					for(int k=j+1;k<=n-1;k++)
						for(int l=k+1;l<=n;l++)
							ma=max(ma,a[i]&a[j]&a[k]&a[l]);
		}else if(m==5){
			for(int i=1;i<=n-4;i++)
				for(int j=i+1;j<=n-3;j++)
					for(int k=j+1;k<=n-2;k++)
						for(int l=k+1;l<=n-1;l++)
							for(int s=l+1;s<=n;s++)
								ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[s]);
		}else if(m==6){
			for(int i=1;i<=n-5;i++)
				for(int j=i+1;j<=n-4;j++)
					for(int k=j+1;k<=n-3;k++)
						for(int l=k+1;l<=n-2;l++)
							for(int s=l+1;s<=n-1;s++)
								for(int r=s+1;r<=n;r++)
									ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[s]&a[r]);
		}else if(m==7){
			for(int i=1;i<=n-6;i++)
				for(int j=i+1;j<=n-5;j++)
					for(int k=j+1;k<=n-4;k++)
						for(int l=k+1;l<=n-3;l++)
							for(int s=l+1;s<=n-2;s++)
								for(int r=s+1;r<=n-1;r++)
									for(int g=r+1;g<=n;g++)
										ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[s]&a[r]&a[g]);
		}else if(m==8){
			for(int i=1;i<=n-7;i++)
				for(int j=i+1;j<=n-6;j++)
					for(int k=j+1;k<=n-5;k++)
						for(int l=k+1;l<=n-4;l++)
							for(int s=l+1;s<=n-3;s++)
								for(int r=s+1;r<=n-2;r++)
									for(int g=r+1;g<=n-1;g++)
										for(int h=g+1;h<=n;h++)
											ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[s]&a[r]&a[g]);
		}else if(m==9){
			for(int i=1;i<=n-8;i++)
				for(int j=i+1;j<=n-7;j++)
					for(int k=j+1;k<=n-6;k++)
						for(int l=k+1;l<=n-5;l++)
							for(int s=l+1;s<=n-4;s++)
								for(int r=s+1;r<=n-3;r++)
									for(int g=r+1;g<=n-2;g++)
										for(int h=g+1;h<=n;h++)
											ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[s]&a[r]&a[g]&a[h]);
		}
	}
	cout<<ma;
	return 0;
}
//Trick||Treat!
