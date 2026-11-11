#include<bits/stdc++.h>
using namespace std;
inline void read(int& a)
{
	int res=0;
	bool fl=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			fl=1;
		}
		c=getchar();
	}	
	while(c>='0'&&c<='9'){
		res=10*res+(c-'0');
		c=getchar();
	}
	if(fl){
		res=-res;
	}
	a=res;
} 
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<1<<"\n";
	cout<<2<<"\n"; 
	return 0; 
}
