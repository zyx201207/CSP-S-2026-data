#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	srand(time(0));
	for(long long i=0;i<e;i++)
	cout<<rand()%1000<<endl;
	return 0;
}
