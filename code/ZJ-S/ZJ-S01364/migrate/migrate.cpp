#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,c,flag,n,t,T,k,d,j,s,s1,s2,t1,t2,f[5010][5010],ff[5010][5010],fff[5010][5010],a[2000010];
int sc(int l,int r){
	int i,s,x;
	s=0;x=l;
	for(i=l;i<=r;i++)
		if(a[i]-a[x]>d){
			x=i-1;
			s++;
		}
	return s+1;
}
bool check(int l,int r){
	int i,s;
	s=0;
	for(i=l+1;i<r;i++){
		if(f[l][i]+f[i][r]==f[l][r])
			s++;
		if(s>1)
			return false;
	}
	return true;
}
bool check2(int l,int r){
	int i,s;
	s=0;
	for(i=l+1;i<r;i++){
		if(f[l][i]+f[i][r]==f[l][r]){
			if(fff[l][i]==1)
				s=s+1;
			else if(ff[l][i]==1)
				;
			else s=s+2;
			if(fff[i][r]==1)
				s=s+1;
			else if(ff[i][r]==1)
				;
			else s=s+2;
			s++;
		}
		if(s>2)
			return fff[l][r]=0;
	}
	return fff[l][r]=(s==2);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(i=1;i<=n;i++)
			cin>>a[i];
		if(n>5000){
		flag=1;
		for(i=2;i<=n;i++)
			if(a[i]-a[i-1]!=a[2]-a[1]){
				flag=0;
				break;
			}
		if(!flag){
			for(i=1;i<=n;i++)
				if(a[i]-a[1]>d)
					break;
			k=i-1;
			if(k==n||k==2||k==n-1)
				cout<<0<<endl;
			else{
				for(i=1;i<k;i++)
					if(a[k+2]-a[i]<=d)
						break;
					else if(a[k+1]-a[i]<=d)
						s1++;
					else s2++;
				for(i=n;i>=k+1;i--)
					if(a[i]-a[k-2]<=d)
						break;
					else if(a[i]-a[k-1]<=d)
						t1++;
					else
						t2++;
				cout<<s1*t2+s2*t1<<endl;
			}
		}
		else{
			t=a[2]-a[1];
//			cout<<t<<" "<<(a[n]-a[1]+t-1)/t<<" "<<(d+t-1)/t<<" ";
			if(d<t*2||a[n]-a[1]<=d)
				cout<<0<<endl;
			else
				cout<<n-1-(d/t*2-1)+1<<endl;
//			if(n-1-((d+t-1)/t*2-1)+1==3){
//				cout<<d<<endl;
//				for(i=1;i<=n;i++)
//					cout<<a[i]<<" ";
//				cout<<endl;
//			}
		}
	}
else{
	s=0;
	for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				f[i][j]=sc(i,j);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				ff[i][j]=check(i,j);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++){
				if(i==4&&j==4)
					;
				s=s+check2(i,j);
			}
		cout<<s<<endl;
}
}
}
