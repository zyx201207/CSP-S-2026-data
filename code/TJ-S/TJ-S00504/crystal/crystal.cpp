#include<bits/stdc++.h>
using namespace std;
long long n,m,p[1000000],a[1000000],maxAns;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>p[i];//输入 
	}
	sort(p,p+n,cmp);
	for(long long i=0;i<n;i++){//枚举基准值 
		for(long long j=0;j<n;j++)a[j]=p[j];//初始化 
		long long num=a[i],step=m,ans=0;
		for(long long j=i;j<n;j++){//枚举ans 
			if(step-(num-a[j])<0){//跳出条件 
				break;
			}
			step-=num-a[j];
			a[j]=num;
			ans++;//计数 
		}
		maxAns=max(maxAns,ans);
	}
	cout<<maxAns;//输出 
	return 0;
}
