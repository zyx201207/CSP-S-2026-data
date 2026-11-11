#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,ans=0,sum=0;
    string r,x;
    cin>>n>>r>>m>>x;
    if(n==m)cout<<1;
    else cout<<0;
    if(r[1]==x[1] and r[2]==x[2]){
	cout<<1;
	sum=1;
	}
	else cout<<0;
	if(r[3]=='D' or r[3]=='F')ans+=1;
	if(x[3]=='D' or x[3]=='F')ans+=1;
	if(ans == 2 or ans == 0)cout<<1;
	else cout<<0;
	if(sum==1 and ans!=1  ){
		if(x[3]=='A' and r[3]=='C' or x[3]=='C' or r[3]=='A'){
			cout<<0;
		}
		else cout<<1;
	}
	else cout<<0;
    return 0;
}
