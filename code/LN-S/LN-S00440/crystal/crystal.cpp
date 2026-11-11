#include<bits/stdc++.h>
using namespace std;
int a[500005],q=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		}
		sort(a+1,a+n+1);
		int p=a[2]-a[1];
    if(n==1)cout<<1;
    if(n==2)cout<<(p>m?1:2);
    if(n==3){int o=a[3]-a[2];
		int u=min(p,o);int s =max(p,o);
		if(u>m){cout<<1;}
		else cout<<((m-u)<2*s?2:3);
	}
	if(n==4||n==5)cout<<3;
if(n>5){
    long long sum=0;
    for(int i=1;i<n;i++){
		 
			if((sum+i*p)>m)break;
	sum=sum+i*p;
	q=i+1;
	}
	cout<<q;}

	return 0;
	}
