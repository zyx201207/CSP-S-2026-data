#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct node{
	int num;
	char st;
};
node a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].st;
	int i=1,j=n;
	while(i<=j){
		if(a[i].st==a[j].st)
			if(a[i].num>=a[j].num){
				a[i].num-=a[j].num;
				j--;
			}
			else{
				a[j].num-=a[i].num;
				i++;
			}
		if(a[i].st!=a[j].st)
		{
			if(a[i].num>=a[j].num){
				ans+=a[j].num;
				a[i].num-=a[j].num;
				j--;
			}
			else{
				ans+=a[i].num;
				a[j].num-=a[i].num;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}