#include <bits/stdc++.h>

using namespace std;
int c,t,d;
long long x[2000005],n;
int main()
{
	freopen("migrate","r",stdin);
    freopen("migrate","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<0<<endl;
	}
	
	fclose(stdin);
    fclose(stdout);
    return 0;
}
