#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200010],ma,p[35],cnt[35],maxn=-1;
bool A=true,B=true,vis[200010];
void dfs(int x,int ans,int num){//下标，值，计数器 
	if(x==n||ans<=maxn)//&运算只会越变越小 
	    return;
	if(num==m){
		maxn=ans;
		return;
	}
	for(int i=x;i<=n;i++){
		if(vis[i])
		    continue;
		if(num+(n-i+1)<=m-1)
		    return;
		if(num==0){
			vis[i]=true;
			dfs(x+1,a[i],num+1);
			vis[i]=false;
		}else{
			vis[i]=true;
			dfs(x+1,ans&a[i],num+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	p[0]=1;
	for(int i=1;i<=30;i++)
	    p[i]=p[i-1]<<1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ma<a[i])
		    ma=a[i];
		if((a[i]+1)&a[i])
		    A=false;
		if(a[i]!=i-1)
		    B=false;
	}
	if(m==1){
		cout<<ma;
	}else if(m==n){
		int t=a[1];
		for(int i=1;i<=n;i++)
		   t=t&a[i];
		cout<<t;
	}else if(m==2&&n>=20){//一定选择相邻数字 （该做法不对） 
		sort(a+1,a+n+1);
		int t=0;
		for(int i=1;i<=n-1;i++){
			int x=a[i]&a[i+1];
			if(t<x)
			    t=x;
		}
		cout<<t;
	}else if(m==n-1){//此处cnt是计数器，记录次幂数量，cnt[x]为n-1即代表去掉一个没有第x位的数字之后第x位能够保留 
		sort(a+1,a+n+1);
		int hist=0;
		for(int i=1;i<=n;i++){
			int t=a[i],j=0;
			while(t){
				if(hist<j)
				    hist=j;//hist少算一位 
				if(t%2)
					cnt[j]++;
				t=t>>1;
				j++;
			}
		}
		for(int i=hist;i>=1;i--){//
			if(cnt[i]==n-1){
				for(int j=1;j<=n;j++){//找到谁没有第i位的1 
					int t=a[j],ans=0,k=0;
					bool flag=false;
					while(t){
						ans=ans+(t%2)*(p[k]);
						t=t>>1;
						k++;
						if(k==i&&t%2==0)
						    flag=true;
					}
					if(k<=i)//等效于k<i+1
					    flag=true;
					if(flag==true){
						cout<<ans;
						return 0;
					}
				}
			}else
			    continue;
		}
		cout<<0;
		return 0;
	}else if(ma<=4){//此处cnt下标1、2、3、4分别指出现次数 
		for(int i=1;i<=n;i++)
		    cnt[i]++;
		if(cnt[4]>=m){//只有4出现次数大于m时才能选4，否则&之后全部变成0 
			cout<<4;
		}else if(cnt[3]>=m){
			cout<<3;
		}else if(cnt[2]+cnt[3]>=m){
			cout<<2;
		}else if(cnt[1]+cnt[3]>=m){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(A){
		sort(a+1,a+n+1);
		int ans=a[n];
		m--;
		for(int i=n-1;i>=1;i--){
			if(m==0){
				cout<<ans;
				return 0;
			}
			ans=ans&a[i];
			m--;
		}
		cout<<ans;
	}else if(B){
		int t=1,k=n-1,ans=0;
		while(m>t){
			t=t<<1;
	    }//while结束时，m<=t,n为t倍数 
	    int x=n/t;
	    t=1;
	    int mus=0;//minus
	    while(n){
	    	ans=k-mus;
	    	mus+=t;
	    	t=t<<1;
	    	if(x==n){
	    		cout<<ans;
	    		return 0;
			}
	    	n=n>>1;
		}
	}else{
		sort(a+1,a+n+1);
		dfs(1,0,0);
		cout<<maxn;
	}
	return 0;
} 
