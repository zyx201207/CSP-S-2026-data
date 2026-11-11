#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n+20];
	long long z(0),d[n+20],ans(0);
	char c[n+20];
	d[0]=0;
	d[1]=1;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		
		z+=a[i];d[i+1]=z+1;
		//cout << d[i] << endl;
	}
	long long l(0),r(0);
	int li(0),ri(0);
	if(z%2==0)
	{
		l=z/2;
		r=z/2;
		r++;
		
		
		for (int i = 1;i<=n;i++)
		{
			if(l-d[i+1]<0)
			{
				li=i;
			}
			if(d[i+1]-r>0)
			{
				ri=i;
				break;
			}
		}
	}
	else
	{
		l=z/2;
		l++;
		r=z/2;
		r++;
		for (int i = 1;i<=n;i++)
		{
			if(l-d[i+1]<0)
			{
				li=i;
				ri=i;
				break;
			}
		}
	}
	//cout << endl;
	//cout << d[li] << " " << d[ri] << endl;
	//cout << li << " " << ri << endl;
	//cout << l << " " << r << endl;
	while(1)
		{
			if((d[ri+1]-r)>=(l-d[li]+1))
			{
				//cout << d[ri+1]-r<< "way";
				if(c[li]!=c[ri])
				{
					ans+=l-d[li]+1;
					//cout << "nb";
				}
				r+=l-d[li]+1;
				l=d[li]-1;
				
				if(r>=d[ri+1])
				{
					ri++;
				}
				li--;
				
			}
			else
			{
				if(c[li]!=c[ri])
				{
					ans+=d[ri+1]-r;
				}
				l-=d[ri+1]-r;
				r=d[ri+1];
				if(l<d[li])
				{
					li--;
				}
				ri++;
			}//cout << endl;
			//cout << ans << endl;
			
	//cout << d[li] << " " << d[ri] << endl;
	//cout << li << " " << ri << endl;
	//cout << l << " " << r << endl;
			if(l==0||r==z+1)
			{
				break;
			}
			
		}
	cout << ans << endl;	
	return 0;
 } 