#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v;
	char s;
}a[200005];
int n;
long long cnt=0;
string x,y;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].v>>a[i].s,cnt+=a[i].v;
	if(cnt%2==0){
		cnt/=2;
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].v;j++){
				if(sum<=cnt)x+=a[i].s;
				else y+=a[i].s;
				sum++;
			}
		}
		long long ans=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[x.size()-i-1])ans++;
		}
		cout<<ans;
	}else{
		cnt/=2;
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].v;j++){
				if(sum<cnt)x+=a[i].s;
				else if(sum!=cnt)y+=a[i].s;
				sum++;
			}
		}
		long long ans=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[x.size()-i-1])ans++;
		}
		cout<<ans;
	}
}