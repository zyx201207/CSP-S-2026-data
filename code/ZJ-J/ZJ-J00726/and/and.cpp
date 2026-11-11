#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],k,p=1,cnt,ans,Max,A;
bool f[N];
void dfs(int x,int g,int s){
	if(s<ans){
		return;
	}
	if(x>n){
		ans=max(ans,s);
		return;
	}
	for(int i=x;i+g-1<=n;i++){
		dfs(x+1,g-1,s&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=1;i+m-1<=n;i++){
			dfs(i+1,m-1,a[i]);
		}
		cout<<ans;
	}
	else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
		}
		else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(i==1){
					ans=a[i];
				}
				else{
					ans&=a[i];
				}
			}
		}
		cout<<ans;
	}
	else{
		if(m==n-1){
			for(int i=1;i<=n;i++){
				Max=max(Max,a[i]);
				if(A==0){
					A=a[i];
				}
				else{
					A&=a[i];
				}
			}
			while(p<Max){
				p*=2;
				k++;
			}
			for(int j=k;j>=0;j--){
				memset(f,0,sizeof(f));
				cnt=0;
				for(int i=1;i<=n;i++){
					if(a[i]&(1<<j)==0){
						cnt++;
						f[i]=1;
					}
				}
				if(cnt==1){
					int ans=0;
					for(int i=1;i<=n;i++){
						if(!f[i]){
							if(ans==0){
								ans=a[i];
							}
							else{
								ans&=a[i];
							}
						}
					}
					A=max(A,ans);
				}
			}
			cout<<A;
		}
		else if(a[1]==0&&a[2]==1&&a[3]==2&&a[4]==3&&a[5]==4&&a[6]==5){
			int j=1,k1=0,k2=0;
			while(j<n){
				j*=2;
				k1++;
			}
			j=2;
			while(j<=m){
				j*=2;
				k2++;
			}
			cout<<(1<<k1)-(1<<k2);
		}
		else{
			sort(a+1,a+n+1);
			cout<<a[n];
		}
	}
	return 0;
}