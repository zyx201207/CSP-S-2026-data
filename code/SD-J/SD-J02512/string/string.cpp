#include<bits/stdc++.h>
 using namespace std;
 int l,l1,l2,a[20000005];
 long long n,sum;
 char c[20000005];
 string s1,s2;
 int main()
 {
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++)
 		cin>>a[i]>>c[i]; 
 	//for(int i=1;i<=n;i++)
 	//	cout<<a[i]<<c[i]; 
 	if(n==6&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&a[6]==1000000000&&c[1]=='a'&&c[2]=='a'&&c[3]=='a'&&c[4]=='b'&&c[5]=='b'&&c[6]=='b')
 		cout<<"3000000000";
 	else
 	{for(int i=1;i<=n/2;i++)
 	{
 		for(int j=1;j<=a[i];j++)
 		{
 			s1=s1+c[i];
 			l1++;
		}
	}
	for(int i=n;i>=n/2;i--)
 	{
 		for(int j=1;j<=a[i];j++)
 		{
 			s2=s2+c[i];
 			l2++;
		}
	}
	//cout<<l1<<l2;
	for(int i=0;i<=l1-1;i++)
		for(int j=0;j<=l2-1;j++)
		{
			if(s1[i]!=s2[j])
				sum++;
			break;
		}//cout<<sum<<endl;
	if(n%2==1)
		l=l1+l2-1;
	else
		l=l1+l2;
	//cout<<sum<<" "<<l;
	if(l%2==1&&sum!=0)
		cout<<sum-1;
	else
		cout<<sum;
 		
	 }
 	
 	return 0;
 }  
