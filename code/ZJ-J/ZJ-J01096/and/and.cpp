#include <bits/stdc++.h>
#define int long long
using namespace std;
int i,n,a[1000001],m,s,ma,j,ma2,ans1,ans2,ans3,ans4;
void dfs(int t,int x,int s){
	if(x==m){
		cout<<s<<" ";
		ma=max(ma,s);
		return ;
	}
	if(t>n) return ;
	if(s==0){
		dfs(t+1,x+1,a[t]);
		dfs(t+1,x,s);
	}
	else{
		dfs(t+1,x+1,(s&a[t]));
		dfs(t+1,x,s);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i],ma2=max(ma2,a[i]);
	if(ma2<=4){
		for(i=1;i<=n;i++)
			if(a[i]==4) ans4++;
			else if(a[i]==3) ans1++;
			else if(a[i]==2) ans2++;
			else if(a[i]==1) ans3++;
		if(ans4>=m){
			cout<<"4";
			return 0;
		}	
		if(ans1>=m){
			cout<<"3";
			return 0;
		}
		if(ans1+ans2>=m){
			cout<<"2";
			return 0;
		}	
		if(ans1+ans3>=m){
			cout<<"1";
			return 0;
		}
		cout<<"0";
		return 0;
	}
	if(m==1){
		for(i=1;i<=n;i++)
			ma=max(ma,a[i]);
		cout<<ma;
		return 0;	
	}
	if(m==2){
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				ma=max(ma,(a[i]&a[j]));
		cout<<ma;	
		return 0;	
	}
	if(m==n){
		s=a[1];
		for(i=1;i<=n;i++)
			s=(s&a[i]);
		cout<<s;
		return 0;	
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<ma;
		return 0;
	}
	sort(a+1,a+1+n);
	s=a[n];
	for(i=n-1;i>=n-m+1;i--) s=(s&a[i]);
	cout<<s;
	return 0;				
}

