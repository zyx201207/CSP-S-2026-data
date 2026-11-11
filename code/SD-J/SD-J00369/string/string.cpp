#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long L;
struct node{
	L x;
	char ch;
};
vector<node> a(N);
int cnt[N],n;
int ans,num;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;   
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].ch;
		cnt[i]=cnt[i-1]+a[i].x;
		int p=i;
		if(i>1&&a[i-1].ch==a[i].ch)
		{
			n--;
			a[i-1].x+=a[i].x;
			i--;
			a.pop_back();	
		}
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<min(cnt[n],cnt[n-1]);
		return 0;
	}
	int i=1,j=n; 
	while(i<=j&&a[i].ch!=a[j].ch)
	{
		if(a[i].x>a[j].x)
		{
			a[i].x=a[i].x-a[j].x;
			num+=a[j].x;
			j--;
			a.erase(a.begin()+j+1);
		}
		if(a[i].x<a[j].x)
		{
			a[j].x=a[j].x-a[i].x;
			num+=a[i].x;
			a.erase(a.begin()+i+1);
			i++;
		}
		if(a[i].x==a[j].x){
			a.erase(a.begin()+j+1);
			a.erase(a.begin()+i+1);
			i++,j--;
		}
	}	
	cout<<num;
	return 0;
}

