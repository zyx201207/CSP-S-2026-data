//QJYZ SN-J01345 YangJunnan
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ull long long
inline ull read()
{
	ull x=0;
	char c=getchar();
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x;
}
bool com(ull x,ull y)
{
	return (x&(ull)2e32-1)>(y&(ull)2e32-1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=read(),m=read();
	ull a[n+10];
	memset(a,0,sizeof(a));
	/*cout<<"INPUT_FINISH"<<"\n";*/
	for(int i=1;i<=n;i++) {a[i]=read();/*cout<<"a["<<i<<"]="<<a[i]<<"\n";*/}
	sort(a+1,a+n+1,com);
	ull ans=a[1];
	//cout<<"upper"<<a[1]<<" ";
	for(int i=2;i<=m;i++)
	{
		ans=(ans&a[i]);
		//cout<<" "<<a[i];
	}
	ull x=(ull)(524288)&(262144);
	//cout<<"\n"<<"ans is"<<x;
	cout<<ans;
	return 0;
}
//11:00-11:40

