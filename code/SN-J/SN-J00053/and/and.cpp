#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],ans=0,sum=0;
string s[N];
vector<string> q;
void check(int x,int y){
	while(x){
	    s[y]+=(x%2)+'0';
	    x/=2;
	}
	int o=s[y].size();
	sum=max(sum,o);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++)
		check(a[i],i);
	for(int i=1;i<=n;i++)
	    q.push_back(s[i]);
	for(int i=sum-1;i>=0;i--){
		for(int j=0;j<n;j++)
		    if(q[j].size()<i) continue;
		    else{
		    	if(q[j][i]=='0') q[j]="2";
			}
		int cnt=0;bool tmp=0;
		for(int j=0;j<n;j++)
		    if(q[j].size()<i+1) tmp=1;
		    else if(q[j]!="2") cnt++;
		if(cnt<m&&!tmp) break;
		else if(cnt<m) continue;
		else{
			for(int j=0;j<n;j++)
			    if(q[j].size()<i) q[j]="2";
			ans+=(int)pow(2,i);
		}
	}
	cout<<ans;
	return 0;
}
