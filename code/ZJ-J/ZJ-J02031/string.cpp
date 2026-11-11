#include<bits/stdc++.h>
using namespace std;
int n,t;
long long a[3][200005],d=1,len=0,ans=0;//1Îª×ó£¬2ÎªÓÒ 
char ch[200005];

long long chong(long long a,long long b,long long a1,long long b1){
	bool l=0,r=0;
	if(a1>=a&&a1<=b) l=1;
	if(b1>=a&&b1<=b) r=1;
	if(l&&r) return b1-a1+1;
	if(l&&!r) return b-a1+1;
	if(!l&&r) return b1-a+1;
	if(!l&&!r) return b-a+1;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	t=n;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		len+=x;
		a[1][i]=d;
		a[2][i]=d+x-1;
		ch[i]=c;
		d+=x;
	}
	
	
	for(int i=1;i<=n/2;i++){
		long long l=len-a[2][i]+1,r=len-a[1][i]+1;
		
		while(a[2][t]>=l&&a[1][t]<=r){
			
			if(ch[t]!=ch[i]){
				ans+=chong(a[1][t],a[2][t],l,r);
			}
			t--;
		}
	}
	cout<<ans;
	
	return 0;
}
