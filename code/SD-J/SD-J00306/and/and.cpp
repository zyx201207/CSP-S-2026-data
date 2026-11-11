#include<bits/stdc++.h>
using namespace std;
#define long long ll
#define endl '\n'
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	int n;
	cin>>n;
	cout<<rand()%n+1<<endl;
	return 0;
}
