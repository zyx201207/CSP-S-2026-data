#include<bits/stdc++.h>
using namespace std;
int a[200005][35],linshi[35],c[35],xiaozu[200005],ans[35];
int n,m,x;
void zhuanerjinzhi(int x,int j){
	int cnt=0;
	while(x){
		if(x%2==0)linshi[++cnt]=0;
		else linshi[++cnt]=1;
		x/=2;
	}
	for(int i=30-cnt+1;i<=30;i++){
		a[j][i]=linshi[30-i+1];
		c[30-cnt+1]++; 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		zhuanerjinzhi(x,i);
	}
	for(int i=1;i<=200001;i++)xiaozu[i]=1;
	for(int i=1;i<=31;i++) ans[i]=1;
	int sum=n;
	for(int i=1;i<=30;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==0&&xiaozu[j]==1)cnt++;
		}
		if(sum-cnt>=m){
			for(int j=1;j<=n;j++){
				if(a[j][i]==0)xiaozu[j]=0;
			}
			sum-=cnt;
		}else{
			ans[i]=0;
		}
	}
	long long zuizhongans=0;
	long long leicheng=1;
	for(int i=30;i>=1;i--){
		zuizhongans+=ans[i]*leicheng;	
		leicheng=leicheng*2;
	}
	cout<<zuizhongans;
	return 0;
}
