#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],mm,t,l,s,k,maxn,w;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		t=s-(s & a[i]);
		if(t>mm){mm=t;l=i;}
		s=(s & a[i]);
	}
	if(m==1){cout<<maxn;return 0;}
	if(m==n){cout<<s;return 0;}
	if(m==2){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				k=max(k,(a[i] & a[j]));
		cout<<k;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i==l) continue;
			k=(k & a[i]);
		}
		cout<<k;
		return 0;
	}
	if(maxn<4){
		for(int i=1;i<=n;i++) b[a[i]]++;
		if(a[3]>=m) cout<<3;
		else{
			if(a[2]>=m) cout<<2;
			else{
				m=m-a[3];
				if(m<=a[2]) cout<<2;
				else{
					if(m<=a[1]) cout<<1;
					else cout<<0;
				}
			}
		}
		return 0;
	}
	if(n<=20){
		if(m==3){
			for(int i=1;i<=n-2;i++)
				for(int j=i+1;j<=n-1;j++)
					for(int k=j+1;k<=n;k++)
						w=max(w,((a[i] & a[j]) & a[k]));
			cout<<w;
			return 0;
		}
		if(m==4){
			for(int i=1;i<=n-3;i++)
				for(int j=i+1;j<=n-2;j++)
					for(int k=j+1;k<=n-1;k++)
						for(int l=k+1;l<=n;l++)
							w=max(w,(((a[i] & a[j]) & a[k])& a[l]));
			cout<<w;
			return 0;
		}
		if(m==5){
			for(int i=1;i<=n-4;i++)
				for(int j=i+1;j<=n-3;j++)
					for(int k=j+1;k<=n-2;k++)
						for(int l=k+1;l<=n-1;l++)
							for(int p=l+1;p<=n;p++)
								w=max(w,((((a[i] & a[j]) & a[k])& a[l])& a[p]));
			cout<<w;
			return 0;
		}
		if(m==6){
			for(int i=1;i<=n-5;i++)
				for(int j=i+1;j<=n-4;j++)
					for(int k=j+1;k<=n-3;k++)
						for(int l=k+1;l<=n-2;l++)
							for(int p=l+1;p<=n-1;p++)
								for(int q=p+1;q<=n;q++)
									w=max(w,(((((a[i] & a[j]) & a[k])& a[l])& a[p])&a[q]));
			cout<<w;
			return 0;
		}
		if(m==7){
			for(int i=1;i<=n-6;i++)
				for(int j=i+1;j<=n-5;j++)
					for(int k=j+1;k<=n-4;k++)
						for(int l=k+1;l<=n-3;l++)
							for(int p=l+1;p<=n-2;p++)
								for(int q=p+1;q<=n-1;q++)
									for(int t=q+1;t<=n;t++)
										w=max(w,((((((a[i] & a[j]) & a[k])& a[l])& a[p])&a[q])&a[t]));
			cout<<w;
			return 0;
		}
		if(m==8){
			for(int i=1;i<=n-7;i++)
				for(int j=i+1;j<=n-6;j++)
					for(int k=j+1;k<=n-5;k++)
						for(int l=k+1;l<=n-4;l++)
							for(int p=l+1;p<=n-3;p++)
								for(int q=p+1;q<=n-2;q++)
									for(int t=q+1;t<=n-1;t++)
										for(int u=t+1;u<=n;u++)
											w=max(w,(((((((a[i] & a[j]) & a[k])& a[l])& a[p])&a[q])&a[t])&a[u]));
			cout<<w;
			return 0;
		}
		if(m==9){
			for(int i=1;i<=n-8;i++)
				for(int j=i+1;j<=n-7;j++)
					for(int k=j+1;k<=n-6;k++)
						for(int l=k+1;l<=n-5;l++)
							for(int p=l+1;p<=n-4;p++)
								for(int q=p+1;q<=n-3;q++)
									for(int t=q+1;t<=n-2;t++)
										for(int u=t+1;u<=n-1;u++)
											for(int v=u+1;v<=n;v++)
												w=max(w,((((((((a[i] & a[j]) & a[k])& a[l])& a[p])&a[q])&a[t])&a[u])&a[v]));
			cout<<w;
			return 0;
		}
		if(m==10){
			for(int i=1;i<=n-9;i++)
				for(int j=i+1;j<=n-8;j++)
					for(int k=j+1;k<=n-7;k++)
						for(int l=k+1;l<=n-6;l++)
							for(int p=l+1;p<=n-5;p++)
								for(int q=p+1;q<=n-4;q++)
									for(int t=q+1;t<=n-3;t++)
										for(int u=t+1;u<=n-2;u++)
											for(int v=u+1;v<=n-1;v++)
												for(int o=v+1;o<=n-1;o++)
													w=max(w,(((((((((a[i] & a[j]) & a[k])& a[l])& a[p])&a[q])&a[t])&a[u])&a[v])&a[o]));
			cout<<w;
			return 0;
		}
	} 
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
