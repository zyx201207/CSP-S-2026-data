#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+5;
void open(string s){
	if(!s.size())return;
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
int n;
int a[N];
char c[N];
ll ans;
int main(){
	open("string");
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[l];
			r--,l++;
			continue;
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				if(c[l]!=c[r])ans+=a[l];
				l++;
				continue;
			}else{
				a[l]-=a[r];
				if(c[l]!=c[r])ans+=a[r];
				r--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
