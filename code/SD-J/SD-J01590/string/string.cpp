#include <iostream>
#include <cstdio>
#include <cstring>
//#define ll long long
using namespace std;
pair<unsigned long long,char> a[210000];
//pair<unsigned long long,char> b[210000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0;
	cin>>n;
	a[0].first=0;a[0].second=0;
	long long len=0;
	for(int i=1;i<=n;i++)
	{
		m++;
		cin>>a[m].first;
		cin>>a[m].second;
		len+=a[m].first;
		if(a[m].second==a[m-1].second)
		{
			m--;
			a[m].first+=a[m+1].first;
			a[m+1].first=0;
			a[m+1].second=0;
		}
	}	
	long long ans=0;
	long long len1=0;
	int l=1,r=m;
	while(len1<len)
	{
		//cout<<l<<" "<<r<<endl;
		if(a[l].second==a[r].second)
		{
			len1=len1+min(a[l].first,a[r].first)*2;
			if(a[l].first>a[r].first) {
				a[l].first-=a[r].first;
				r--;
			}
			else if(a[l].first<a[r].first){
				a[r].first-=a[l].first;
				l++;
			}		
			else if(a[l].first==a[r].first){
				a[r].first=0;a[l].first=0;
				l++,r--;
			}
		//	cout<<"first"<<endl;	
		}
		else{
			ans+=min(a[l].first,a[r].first);
			len1=len1+min(a[l].first,a[r].first)*2;
			if(a[l].first>a[r].first) {
				a[l].first-=a[r].first;
				r--;//cout<<"1"<<" "<<a[l].first;
			}
			else if(a[l].first<a[r].first){
				a[r].first-=a[l].first;
				l++;//cout<<"2"<<" "; 
			}		
			else if(a[l].first==a[r].first){
				a[r].first=0;a[l].first=0;
				l++,r--;//cout<<"3"<<" ";
			}
			//cout<<"second"<<" "<<a[l].first<<" "<<a[r].first<<endl;
		}
	}
	cout<<ans<<endl;
	return 0; 
}
