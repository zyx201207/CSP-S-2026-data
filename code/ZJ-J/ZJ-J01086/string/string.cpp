#include<bits/stdc++.h>
using namespace std;
int n;
struct Node{
	int s;
	char id;
}x[200005]; 
long long ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i].s>>x[i].id;
	long long f1=1,f2=n,s1=0,s2=0;
	while(f1<f2){
		if(s1+x[f1].s<s2+x[f2].s){
			if(x[f1].id!=x[f2].id) ans+=x[f1].s;
			s1=s1+x[f1].s;
			s2=s2+x[f1].s;
			x[f2].s-=x[f1].s;
			f1++;
		}
		else{
			if(x[f1].id!=x[f2].id) ans+=x[f2].s;
			s1=s1+x[f2].s;
			s2=s2+x[f2].s;
			x[f1].s-=x[f2].s;
			f2--;
		}
	}
	cout<<ans;
	return 0;
}