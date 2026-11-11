#include<bits/stdc++.h>
#define ll long long
#define N 500015
using namespace std;
template<typename T>
inline void read(T &s){
	int f=1;
	char ch=getchar();
	s=0;
	while(!isdigit(ch)){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	s*=f;
}
int n;
ll m,a[N],p[N],s[N],ss[N];
ll calc(int lt,int rt){
	return (rt-lt+1)*1ll*s[rt]-ss[rt-1]+ss[max(0,lt-2)];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n); read(m);
	for(int i=1;i<=n;++i)
		read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i){
		p[i]=a[i+1]-a[i];
		s[i]=s[i-1]+p[i];
		ss[i]=ss[i-1]+s[i];
	}
	int ans=1;
	for(int i=1;i<n;++i){
		int lt=i,rt=n-1,mid;
		while(lt<=rt){
			mid=lt+rt>>1;
			if(calc(i,mid)<=m)
			{
				lt=mid+1;
				ans=max(ans,mid-i+2);
			}
			else
				rt=mid-1;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
