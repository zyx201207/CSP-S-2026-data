#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long m[N];
char q[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char s;
		cin>>a>>s;
		m[i]=a;
		q[i]=s;
	}
	int l=1;
	int r=n;
	int sum=0;
	while(l<r)
	{
		if(m[l]==m[r])
		{
			if(q[l]==q[r])
			{
				l++;
				r--;
			}else{
				l++;
				r--;
				sum+=m[l];
			}
		}
		if(m[l]!=m[r])
		{
			if(q[l]!=q[r])
			{
				if(m[l]<m[r])
				{
					m[r]-=m[l];
					sum+=m[l];
					l++;
				}
				if(m[l]>m[r])
				{
					m[l]-=m[r];
					sum+=m[r];
					r--;
				}
			}
			if(q[l]==q[r])
			{
				if(m[l]<m[r])
				{
					int it=m[r]-m[l];
					for(int i=l+1;;i++)
					{
						if(q[i]!=q[l])
						{
							if(m[i]<it)
							{
								sum+=m[i];
								it-=m[i];
							}else{
								sum+=it;
								if(m[i]==0)
								{
									l=i+1;
								}else{
									l=i;
								}
								
								r--;
								m[l]=m[l]-it;
								break;
							}
						}else{
							if(m[i]<it)
							{
								it-=m[i];
							}else{
								if(m[i]==0)
								{
									l=i+1;
								}else{
									l=i;
								}
								r--;
								m[l]=m[l]-it;
								break;
							}
						}
					}
				}
				if(m[l]>m[r])
				{
					int it=m[l]-m[r];
					for(int i=r-1;;i--)
					{
						if(q[i]!=q[r])
						{
							if(m[i]<it)
							{
								sum+=m[i];
								it-=m[i];
							}else{
								sum+=it;
								if(m[i]==0)
								{
									r=i-1;
								}else{
									r=i;
								}
								l++;
								m[r]=m[r]-it;
								break;
							}
						}else{
							if(m[i]<it)
							{
								it-=m[i];
							}else{
								if(m[i]==0)
								{
									r=i-1;
								}else{
									r=i;
								}
								l++;
								m[r]=m[r]-it;
								break;
							}
						}
					}
				}
			}
		}
	}
	cout<<sum;
	
	return 0;
}
