#include<bits/stdc++.h>
#define int long long
using namespace std;
int mx=INT_MIN,n,m,a[200005];
bool A1=true,A2=true;
int qp(int n,int m){
	int sum=1;
	while(m--)sum*=n;
	return sum;
}
int len;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	len=qp(2,n)-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(log2(a[i]+1)!=(int)log2(a[i]+1))A1=false;
		if(a[i]!=i-1)A2=false;
	}
	if(m==1){
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
	}else if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				mx=max(mx,(a[i]&a[j]));
		cout<<mx;
	}else if(m==n){
		int sum=len;
		for(int i=1;i<=n;i++)
			sum&=a[i];
		cout<<sum;
	}else if(A1||A2){
		sort(a+1,a+1+n,greater<int>());
		int sum=len;
		for(int i=1;i<=m;i++)sum&=a[i];
		cout<<sum;
	}else{
		for(int i=1;i<=len;i++){
			int k=i,cnt=0,sum=len,idx=1;
			while(k){
				if(k&1)cnt++,sum&=a[idx];
				idx++;
				k>>=1;
			}
			if(cnt==m)mx=max(mx,sum);
		}
		cout<<mx; 
	}
	return 0;
}//11:07骗完分 ,这题特殊性质不少，能拿个75分（最高） ,攻第4题 
