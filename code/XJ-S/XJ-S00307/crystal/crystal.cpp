#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[500005];
int b[500005];//各个数距离平均数的值 
int a1[500005];
int b1[500005];//中位数 
int b2[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0,ans=0,f=0,sum1=0,sum2=0,sum3=0,f1=0,ans1=0,ans2=0,ans3=0,m1,m2,m3;
	scanf("%lld%lld",&n,&m);
	m1=m;
	m2=m;
	m3=m;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		a1[i]=a[i];
		sum+=a[i];
	}sort(a1,a1+n);
	sum=ceil(sum/(n*1.0));//求平均值 
	sum1=a1[n/2];
	sum2=a1[n-1];
	for(int i=0;i<n;i++){
		b1[i]=(sum1-a[i]);
		if(b1[i]<0){
			f1++;
			b1[i]=1000000000000000000;
		}
	}
	for(int i=0;i<n;i++){
		b[i]=(sum-a[i]);
		if(b[i]<0){
			f++;
			b[i]=1000000000000000000;
		}
	}
	for(int i=0;i<n;i++){
		b2[i]=(sum2-a[i]);
	}
	sort(b,b+n);
	for(int i=0;i<n-f;i++){
		if(m-b[i]>=0){
			m-=b[i];
			ans+=1;
		}else{
			break;
		}
		
	}//方案一平均数
	sort(b1,b1+n);
	for(int i=0;i<n-f1;i++){
		
		if((m1-b1[i])>=0){
			m1-=b1[i];
			ans1+=1;
		}else{
			break;
		}
		
	}//方案二中位数
	sort(b2,b2+n);
	for(int i=0;i<n;i++){
		if(m2-b2[i]>=0){
			m2-=b2[i];
			ans2+=1;
		}else{
			break;
		}
		
	}//方案三最大值
	
	cout<<max(ans,max(ans1,ans2));
	
	return 0;
} 
