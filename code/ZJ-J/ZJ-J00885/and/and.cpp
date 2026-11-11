#include<bits/stdc++.h>
using namespace std;
bool flag1,flag2,flag11,flag22;
long long n,m,i,ma,a[200010],b[200010],j,pd1[50000],pd2[50000];
void dg(long long t,long long mm){
	if(mm>m) return ;
	if(t==n+1){
		if(mm==m){
			long long ans=b[1];
			for(long long i=2;i<=m;i++){
				ans&=b[i];
			}
			ma=max(ma,ans);
		}
		return ;
	}
	b[mm+1]=a[t];
	dg(t+1,mm+1);
	b[mm+1]=0;
	dg(t+1,mm);
}
bool cmp(long long q,long long h){
	return q>h;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=30;i++){
		long long sum=1;
		for(j=1;j<=i;j++){
			sum*=2;
		}
		pd1[i]=sum;
		pd2[i]=sum-1;
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
		flag1=flag2=0;
		for(j=1;j<=30;j++){
			if(a[i]==pd1[j]){
			    flag1=1;
			    break;
			}
			if(a[i]==pd2[j]){
				flag2=1;
				break;
			}
		}
		if(!flag1) flag11=1;
		if(!flag2) flag22=1;
	}
	if(n<=20){
		dg(1,0);
		cout<<ma;
	}else if(m==1||!flag11){
		long long mn=0;
		for(i=1;i<=n;i++){
			mn=max(mn,a[i]);
		}
		cout<<mn;
	}else if(m==n){
		long long sum=a[1];
		for(i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}else if(m==2&&m<=10000&&n<=10000){
		long long mn=0;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				mn=max(mn,a[i]&a[j]);
			}
		}
		cout<<mn;
	}else if(m==n-1){
		long long mn=0,sum=a[1];
		for(i=2;i<=n;i++){
			sum&=a[i];
		}
		for(i=1;i<=n;i++){
			mn=max(mn,sum|a[i]);
		}
		cout<<mn;
	}else{
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
	}
	return 0;
}
