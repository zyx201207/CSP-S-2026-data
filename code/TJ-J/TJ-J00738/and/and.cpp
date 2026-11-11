#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int a[200005];
int t1[25];
int t2[5];
bool flag1=1;
bool flag2=1;
bool vis[25];
int ans=-0x3f3f3f3f;
int tmp=2147483647;
void dfs(int i,int tmp,bool vis[]){//有n个数，已经取了i个,要取m个,目前数字为tmp,vis[]表示哪个取了/没取. 
	if(i==m){
		ans=max(ans,tmp);
		return;
	}
	int cnt=tmp;
	for(int k=i+1;k<=n;k++){
		if(!vis[k]){
			vis[k]=1;
			tmp&=a[k];
			dfs(i+1,tmp,vis);
			vis[k]=0;
			tmp=cnt;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(flag1){
			bool f=0;
			for(int j=0;j<=20;j++)
				if(pow(2,j)==a[i]+1){
					f=1;
					t1[j]++;
					break;
				}
			if(!f) flag1=0;
		}
		if(a[i]>4) flag2=0;
		if(flag2) t2[a[i]]++;
	}
	//#6
	if(m==1){
		int ans=-0x3f3f3f3f;
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	//#7
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	//#8-10
	if(m==2){
		int ans=-0x3f3f3f3f;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		//O(n^2)
		cout<<ans;
		return 0;
	}
	//#13
	if(flag1){
		int sum=0;
		for(int i=20;i>=0;i--){
			sum+=t2[i];
			if(sum>=m){
				cout<<pow(2,i);
				return 0;
			}
		}
	}
	//#16,17
	if(flag2){
		if(t2[4]>=m){
			cout<<4;
			return 0;
		}
		if(t2[3]>=m){
			cout<<3;
			return 0;
		}
		if(t2[3]+t2[2]>=m){
			cout<<2;
			return 0;
		}
		if(t2[3]+t2[1]>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
	}
	//#1-5
	for(int i=1;i<=20;i++) vis[i]=0;
	dfs(n,0,vis);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
