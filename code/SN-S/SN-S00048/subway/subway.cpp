#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
struct subway{
	int t,e;
};
int w[505];
int d,q,c,n,m,
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		cin>>w[i];
	cout<<rand()%10000;
	return 0;
}
