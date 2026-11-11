#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=0;
int maxn=-1e12-5,minn=1e12+5;
bool fm=1;
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i-1]-a[i-2]!=a[i]-a[i-1]) fm=0;
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1,cmp);//从小到大排序
	//特判A,B：等差数列 
	if(fm&&n>2){
		int tot=0,c=a[2]-a[1];
		ans=1;
		for(int i=c;i<=n-1;i+=c){
			if(tot+i>m) break;
			tot+=i;
			ans++;
		}
		cout<<ans;
		return 0;
	} 
	//常规
	int num=1;
	for(int s=minn;s<=maxn;s++){//枚举让它们接近的数
		int h=m,tot=0;
		while(s>=a[num]&&num<=n) num++;
		num--;
		for(int i=num;i>=1;i--){
			h=h-(s-a[i]);
			if(h<0) break;//若操作数不够了就跳出
			tot++;
		}
		ans=max(ans,tot);
	}
	cout<<ans;
	return 0;
} 
