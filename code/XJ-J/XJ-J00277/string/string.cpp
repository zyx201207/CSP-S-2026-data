#include<cstdio>
long long int  ans;
int n,a;
long long int num1,num2;
long long int l[210000],r[210000];
char c[210000];
int main()
{
	long long int i,j;
    FILE *in = fopen("string.in","r");
    FILE *out = fopen("string.out","w");
	fscanf(in,"%d",&n);
	j=1;
	for(i=1;i<=n;i++)
	{
		fscanf(in,"%d %c",&a,&c[i]);
		l[i]=j;
		j+=a;
		r[i]=j-1;
	}
	i=1;
	j=n;
	num1=r[i]-l[i]+1;
	num2=r[j]-l[j]+1;
	while(i<j)
	{
		if(c[i]==c[j])
		{
			if(num1>num2)
			{
				num1-=num2;
				j--;
				num2=r[j]-l[j]+1;
			}
			else if(num1<num2)
			{
				num2-=num1;
				i++;
				num1=r[i]-l[i]+1;
			}
			else
			{
				j--;
				num2=r[j]-l[j]+1;
				i++;
				num1=r[i]-l[i]+1;
			}
		}
		else
		{
			if(num1>num2)
			{
				num1-=num2;
				ans+=num2; 
				j--;
				num2=r[j]-l[j]+1;
			}
			else if(num1<num2)
			{
				num2-=num1;
				ans+=num1;
				i++;
				num1=r[i]-l[i]+1;
			}
			else
			{
				ans+=num1;
				j--;
				num2=r[j]-l[j]+1;
				i++;
				num1=r[i]-l[i]+1;
			}
		}
	}
	fprintf(out,"%lld",ans);
	return 0;
} 
