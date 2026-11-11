#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long ans,lo;
long long cnt,mi;
struct node{
	long long x;
	char a;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		char b;
		cin>>x>>b;
		a[i].x=x,a[i].a=b;
		lo+=x;
	}
	mi=(lo)/2;
	
	long long l=1,r=n;
	while(l<r)
	{
		//cout<<l<<" "<<r<<endl;
		//cout <<a[l].x<<" " <<a[r].x<<endl;
		if(cnt>=mi)
		{
			break;
		}
		if(a[l].a==a[r].a)
		{
			if(a[l].x>a[r].x)
			{
				a[l].x-=a[r].x;
				cnt+=a[r].x;
				r--;
			}
			else if(a[l].x==a[r].x)
			{
				
				cnt+=a[l].x;
				l++;r--;
			}
			else{
				
				a[r].x-=a[l].x;
				cnt+=a[l].x;
				l++;
			}
			
		}
		else 
		{
			if(a[l].x>a[r].x)
			{
				a[l].x-=a[r].x;
				ans+=a[r].x;
				cnt+=a[r].x;
				r--;
			}
			else if(a[l].x==a[r].x)
			{
				
				ans+=a[l].x;
				l++;r--;
			}
			else{
				
				ans+=a[l].x;
				cnt+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
	}
	cout<<min(ans,mi);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
