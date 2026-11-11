#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int a[500005],ans=0;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	
	int l=1,r=1,nowmax=a[1],nowcost=0;
	while(l<=n)
	{
		while(r<=n)
		{
			//r->r+1
			int willadd=(r-l+1)*(a[r+1]-nowmax);
			if(nowcost+willadd<=m)r++;
			else break;
			nowmax=a[r];nowcost+=willadd;
			
			ans=max(ans,r-l+1);
			//cout<<l<<' '<<r<<' '<<nowcost<<endl;
		
		}
		
		nowcost-=(nowmax-a[l]);l++;
		//cout<<l<<' '<<r<<' '<<nowcost<<endl;
			ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
//14:56done
//s t1最快的一次
//上午main忘写retrun0了
//后头有时间自己造一组 
//滚木出题人大样例不给最大的
 
