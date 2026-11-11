#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char w[100005];
int q;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
	if(c1!=c2) printf("0000");
	else 
	{
		q=s1.length();
		cout<<q;
	}
	return 0;
}
