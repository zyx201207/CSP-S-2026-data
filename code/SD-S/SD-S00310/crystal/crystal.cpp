#include<bits/stdc++.h>
using namespace std;
inline long long rd(){long long f=1,x=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
inline void wt(long long x,int opt){int top=0;char a[105];if(x<0)putchar('-'),x=-x;do{a[++top]=x%10+'0';x/=10;}while(x);for(int i=top;i>=1;i--)putchar(a[i]);if(opt==1)putchar(' ');if(opt==2)putchar('\n');}
int n;
long long m,a[500005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();m=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	sort(a+1,a+n+1);
	int cnt=1,ans=1;
	int l=1;
	long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=1ll*(i-l)*(a[i]-a[i-1]);
		cnt++;
		while(sum>m&&l<=i){
			sum-=a[i]-a[l];
			cnt--;
			l++;
		}
		ans=max(ans,cnt);
	}
	wt(ans,2);
}

