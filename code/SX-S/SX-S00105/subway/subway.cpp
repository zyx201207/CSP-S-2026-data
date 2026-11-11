#include<bits/stdc++.h>
using namespace std;
int w[500005];
int x[500005];
int y[500005];
struct node{
	int k,a,t,
}b[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q,k;
    cin>>c>>n>>m>>d>>q;
    fr(i,1,m)
    {
        cin>>w[i];
    }
    fr(i,1,n)
    {
        cin>>b[i].k;
        fr(j,1,b[i].k){
			cin>>b[i].a>>b[i].t;
		}
    }
    fr(i,1,q){
    	cin>>x[i]>>y[i];
	}
    if(c>=8&&c<=11)
    {

    }
    else if(c>=12&&c<=19){

	}
    return 0;
}