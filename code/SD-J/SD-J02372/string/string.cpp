#include <iostream>
using namespace std;
int n,cnt,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string l,b,z;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		while(a--) l+=b;
	}
	for(int i=l.size();i>=1;i--){
		z+=l[i];
	}
	for(int i=1;i<=l.size();i++)
	{
		if(l[i]!=z[i]) cnt++;
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
