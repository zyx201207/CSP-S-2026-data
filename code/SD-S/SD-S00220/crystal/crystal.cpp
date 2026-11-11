#include <bits/stdc++.h>
#define int long long
using namespace std;
long long a[500010],n,m,cnt;
deque<int> q;
int read(){
	int res=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	int i=2,num=a[1],cnt=1,ans=m,now=1;
	q.push_back(1);
	while(i<=n){
		if(!q.empty()){
			if(ans-(now*(a[i]-num))>=0){
				ans-=now*(a[i]-num);
				now++;
//				cout<<now<<" "<<i<<" "<<ans<<endl;
				cnt=max(now,cnt);
				q.push_back(i);
				num=a[i];
				i++;
			}else{
				now--;
				ans+=(num-a[q.front()]);
				q.pop_front();
			}
		}else{
			q.push_back(i);
			num=a[i];
			now=1;
			ans=m;
			i++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}

