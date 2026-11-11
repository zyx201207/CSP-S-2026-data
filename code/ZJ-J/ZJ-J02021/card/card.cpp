#include<bits/stdc++.h>
using namespace std;
int card_start[500005],card_now[500005],sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;

	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>card_start[i];
	}
	if(m==1){
		cout<<n;
	}
	
	
	return 0;
}
