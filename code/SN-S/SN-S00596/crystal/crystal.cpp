#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,flagA,flagB,mx=LLONG_MIN,ans,sum,a[N];
inline long long read(){
	long long ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=(ans<<1)+(ans<<3)+ch-'0';
		ch=getchar();
	}
	return f*ans;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==a[i-1]) flagA++;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i-1]-a[i-2]==a[i]-a[i-1]) flagB++; 
	}
	if(flagA==n-1){//特殊A 
		cout<<n;
		return 0;
	}
	if(flagB==n-2){//特殊B 
		long long ansB=m/(a[2]-a[1]);
		cout<<ansB;
		return 0;
	}
	for(int i=2;i<=n;i++){//当所有小于第i个魔法石都向看齐 
		ans=1,sum=0; 
		for(int j=i;j>=2;j--){//从离他最近的开始操作，看以共能有多少个魔法石和第i相等 
			sum+=a[i]-a[j-1];
			ans++;//已经有一个魔法石与第i个魔法石相等了，总数+1 
			if(sum>m){//操作数大于可操作数了，最后那个魔法石不要（-1） 
				ans--;
				break;
			}if(sum==m){//等于，刚刚好 
				break;
			}
		} 
		mx=max(ans,mx);
	}
//	for(int i=1;i<=n;i++){
	//	cout<<a[i]<<" ";
//	}
	if(mx==1){
		cout<<"0";
	}else{
		cout<<mx;
	}
	return 0;
}
