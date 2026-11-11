#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long a,b,d=0,m[24]={0},q=0;
    string c;
    cin>>a;
    for(int i=0;i<a;i++)
    {
    	cin>>b;
    	d=d+b;
    	cin>>c;
		m[c[0]-'a']++;
	}
	for(int i=0;i<24;i++)
	{
		if(m[i]!=0)
		{
			q++;
		}
	}
	if(q==1)
	{
		cout<<'0';
	}
	else 
	{
		cout<<d/q;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}