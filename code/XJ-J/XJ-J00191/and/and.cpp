#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxx,maxxx,sum;
long long a1[200005];
int a,b,c,d,e,f,g,h,i,j,k,l,o;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a1[i];
		if(a1[i]>maxx) maxxx=a1[i];
	}
	if(m==1)
	{
		cout<<maxxx;
		return 0;
	}
	else if(m==2)
	{
		int x,y;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				long long sum;
				sum=a1[i]&a1[j];
				if(sum>maxx) 
				{
					maxx=sum;
					x=a1[i];
					y=a1[j];
				}
			}
		 } 
		cout<<maxx;
		return 0;
	}
	else if(m==3)
	{
		for(a=1;a<=n;a++)
		{
			for(b=a+1;b<=n;b++)
			{
				for(c=b+1;c<=n;c++)
				{
					long long sum;
					sum=a1[a]&a1[b]&a1[c];
					if(sum>maxx) maxx=sum;
				}
				
			}
		 } 
		cout<<maxx;
		return 0;
	}
	else if(m==4)
	{
		for(a=1;a<=n;a++)
		{
			for(b=a+1;b<=n;b++)
			{
				for(c=b+1;c<=n;c++)
				{
					for(d=c+1;d<=n;d++)
					{
						long long sum;
						sum=a1[a]&a1[b]&a1[c]&a1[d];
						if(sum>maxx) maxx=sum;
					}
					
				}
				
			}
		 } 
		cout<<maxx;
		return 0;
	}
	else if(m==5)
	{
		for(a=1;a<=n;a++)
		{
			for(b=a+1;b<=n;b++)
			{
				for(c=b+1;c<=n;c++)
				{
					for(d=c+1;d<=n;d++)
					{
						for(e=d+1;e<=n;e++)
						{
							long long sum;
							sum=a1[a]&a1[b]&a1[c]&a1[d]&a1[e];
							if(sum>maxx) maxx=sum;
						}
						
					}
					
				}
				
			}
		 } 
		cout<<maxx;
		return 0;
	}
	else if(m==6)
	{
		for(a=1;a<=n;a++)
		{
			for(b=a+1;b<=n;b++)
			{
				for(c=b+1;c<=n;c++)
				{
					for(d=c+1;d<=n;d++)
					{
						for(e=d+1;e<=n;e++)
						{
							for(f=e+1;f<=n;f++)
							{
								long long sum;
								sum=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f];
								if(sum>maxx) maxx=sum;
							}
							
						}
						
					}
					
				}
				
			}
		 } 
		cout<<maxx;
		return 0;
	}
	else if(m==7)
	{
		for(a=1;a<=n;a++)
		{
			for(b=a+1;b<=n;b++)
			{
				for(c=b+1;c<=n;c++)
				{
					for(d=c+1;d<=n;d++)
					{
						for(e=d+1;e<=n;e++)
						{
							for(f=e+1;f<=n;f++)
							{
								for(g=f+1;g<=n;g++)
								{
									long long sum;
									sum=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g];
									if(sum>maxx) maxx=sum;
								}
								
							}
							
						}
						
					}
					
				}
				
			}
		 } 
		cout<<maxx;
		return 0;
	}
	else if(m==8)
	{
		for(a=1;a<=n;a++)
			for(b=a+1;b<=n;b++)
				for(c=b+1;c<=n;c++)
					for(d=c+1;d<=n;d++)
						for(e=d+1;e<=n;e++)
							for(f=e+1;f<=n;f++)
								for(g=f+1;g<=n;g++)
									for(h=g+1;h<=n;h++)sum=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h];if(sum>maxx) maxx=sum;
		cout<<maxx;
		return 0;
	}
	else if(m==9)
	{
		for(a=1;a<=n;a++)
			for(b=a+1;b<=n;b++)
				for(c=b+1;c<=n;c++)
					for(d=c+1;d<=n;d++)
						for(e=d+1;e<=n;e++)
							for(f=e+1;f<=n;f++)
								for(g=f+1;g<=n;g++)
									for(h=g+1;h<=n;h++)
										for(i=h+1;i<=n;i++)sum=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i];if(sum>maxx) maxx=sum;																						 
		cout<<maxx;
		return 0;
	}
	else if(m==10)
	{
		for(a=1;a<=n;a++)
			for(b=a+1;b<=n;b++)
				for(c=b+1;c<=n;c++)
					for(d=c+1;d<=n;d++)
						for(e=d+1;e<=n;e++)
							for(f=e+1;f<=n;f++)
								for(g=f+1;g<=n;g++)
									for(h=g+1;h<=n;h++)
										for(i=h+1;i<=n;i++)
											for(j=i+1;j<=n;j++) sum=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j];if(sum>maxx) maxx=sum;	
																													
												
		cout<<maxx;
		return 0;
	}
	else if(m==11)
	{
		for(a=1;a<=n;a++)
			for(b=a+1;b<=n;b++)
				for(c=b+1;c<=n;c++)
					for(d=c+1;d<=n;d++)
						for(e=d+1;e<=n;e++)
							for(f=e+1;f<=n;f++)
								for(g=f+1;g<=n;g++)
									for(h=g+1;h<=n;h++)
										for(i=h+1;i<=n;i++)
											for(j=i+1;j<=n;j++) 
												for(k=j+1;k<=n;k++)	sum=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k];if(sum>maxx) maxx=sum;	

																													
												
		cout<<maxx;
		return 0;
	}
	else if(m==12)
	{
		for(a=1;a<=n;a++)
			for(b=a+1;b<=n;b++)
				for(c=b+1;c<=n;c++)
					for(d=c+1;d<=n;d++)
						for(e=d+1;e<=n;e++)
							for(f=e+1;f<=n;f++)
								for(g=f+1;g<=n;g++)
									for(h=g+1;h<=n;h++)
										for(i=h+1;i<=n;i++)
											for(j=i+1;j<=n;j++) 
												for(k=j+1;k<=n;k++)	
													for(l=k+1;l<=n;l++ )sum=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[l];if(sum>maxx) maxx=sum;
													

																													
												
		cout<<maxx;
		return 0;
	}
	else if(m==13)
	{
		for(a=1;a<=n;a++)
			for(b=a+1;b<=n;b++)
				for(c=b+1;c<=n;c++)
					for(d=c+1;d<=n;d++)
						for(e=d+1;e<=n;e++)
							for(f=e+1;f<=n;f++)
								for(g=f+1;g<=n;g++)
									for(h=g+1;h<=n;h++)
										for(i=h+1;i<=n;i++)
											for(j=i+1;j<=n;j++) 
												for(k=j+1;k<=n;k++)	
													for(l=k+1;l<=n;l++ )
														for(o=l+1;o<=n;o++) sum=a1[a]&a1[b]&a1[c]&a1[d]&a1[e]&a1[f]&a1[g]&a1[h]&a1[i]&a1[j]&a1[k]&a1[l]&a1[o];if(sum>maxx) maxx=sum;
													
													

																													
												
		cout<<maxx;
		return 0;
	}
	return 0;
}

