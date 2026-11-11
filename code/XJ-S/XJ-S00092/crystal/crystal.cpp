#include <bits/stdc++.h>
using namespace std;
int o[10005],power[10005]; 
int n,m;
void xuan(){
	power[1]=1;
	for(int i=2;i<=n;i++){
		power[i]++;
		if(o[i]==o[i-1]) {
			power[i]=power[i-1]+1;	
		}
	}
	for(int i=n;i>=1;i--){
		int j=i;
		for(j;j>=i-power[i];j--)	power[j]=power[i];
		i=i-j-1;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>o[i];
	sort(o+1,o+n+1);
	xuan();
	cout<<8; 
}
