#include<bits\std c++.h>
using namespace std;
int main()
{
	freopen("and.in" "r"stdin)
	freopen("and.out" "w"stout)
	int M[110];
	int N[20010];

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>N[i];
		M[N[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(M[N[i]]==0)
		continue;
		else
		{
			cout<<N[i]<<" ";
			M[N[i]]=0;
		}
	}
	
	return 0;
}
