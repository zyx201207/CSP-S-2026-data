#include <iostream>
#include <cstdio>
using namespace std; 

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	char answer[4] = {'0','0','0','0'};
	int aa =0;
	char ab[3] = {0};
	int ba = 0;
	char bb[3] = {0};
	cin>>aa;
	cin>>ab;
	cin>>ba;
	cin>>bb;
	if(aa==ba)
	{
		answer[0] = '1';
		if(ab[0]==bb[0]&&ab[1]==bb[1])
	{
		answer[1] = '1';
		if((ab[2]<'D'&&bb[2]<'D')||(ab[2]>'C'&&bb[2]>'C'))
		{
			answer[2] = '1';
			if(ab[2] - 1 == bb[2] || bb[2] - 1 == ab[2])
			answer[3] = '1';
		}
	}
	}
	
	cout<<answer<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
