#include <bits/stdc++.h>
using namespace std;
long long n,y,ans,x,a[100005],a1[100005],zj,yjs,mi,t=1,h=1;
string s,s2;
char c;
bool d;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>y;
		x+=y;
		a[i]=y;
		cin>>c;
		s[i-1]=c;
		
	}
	if(x%2==1) d=1;
	zj=(x+1)/2;//存
	for(int i=0;i<n;i++)
	{
		ans+=a[i];
		if(ans>zj){
			yjs=i;
			break;
		}
	}//找越界
	for(int i=n-1;i>=yjs;i--)
	{
		a1[n-i]=a[i+1];
	}
	a[yjs]-=ans-zj;
	a1[yjs]=ans-zj;//处理越界
	
	if(d) a[yjs]--;
	if(d) zj--;
	//cout<<x<<endl<<zj<<endl<<ans<<endl;
	for(int i=n-1;i>=0;i--) s2[n-i-1]=s[i];
	//for(int i=0;i<yjs;i++) cout<<s[i]<<" ";
	//for(int i=0;i<yjs;i++) cout<<s2[i]<<" ";
	//for(int i=1;i<=yjs;i++) cout<<a[i]<<" ";
	//for(int i=1;i<=yjs;i++) cout<<a1[i]<<" ";
	ans=0;
	for(;zj>0;)
	{
		mi=min(a[t],a1[h]);
		if(s[t-1]!=s2[h-1]) ans+=mi;
		zj=zj-mi;
		a[t]-=mi;
		a1[h]-=mi;
		if(a[t]==0) t++;
		if(a1[h]==0) h++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
