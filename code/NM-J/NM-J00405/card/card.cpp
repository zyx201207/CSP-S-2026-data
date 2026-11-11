#include<bits/stdc++.h>
using namespace std;
int n,m;
struct cadr{
	int name;
	int time;
};cadr card[300005];
int zu[500005];
int main()
{
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>zu[i];
	}
	for(int i=1;i<=m;i++){
		card[i].name=i;
	}
	for(int i=1;i<=n;i++){
		
	}	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

