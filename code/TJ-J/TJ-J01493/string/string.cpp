 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	long long n;
 	cin>>n;
 	string s;
 	long long h=0;
 	for(int i=1;i<=n;i++)
 	{
 		int a;
 		char c;
 		cin>>a>>c;
 		for(int j=h;j<a;j++,h++)
 		{
 			s[j]=c;
		}
	}
	long long q=0;
	for(int i=0;i<s.size();i++)
	{
	 	if(s[i]!=s[s.size()-i-1])
	 	{
	 		s[i]=s[s.size()-i];
	 		q++;
		}
	}
	cout<<q;
 	return 0;
 }
