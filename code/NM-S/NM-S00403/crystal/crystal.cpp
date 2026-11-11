#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans,c,r,max_ans=-1,g;
int op;
long long q[500010],d[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	c=m;
	for(int i=0;i<n;i++){
		cin>>q[i];
		cnt+=q[i];
		g=q[i];
	}
	sort(q,q+n);
	g=q[n-1];
	op=cnt/n;
	for(int k=op;k<g;k++){
		ans=0,m=c,r=0;
		for(int i=0;i<n;i++){
		if(k>=q[i]){
			d[i]=abs(op-q[i]);r++;
			}
		}
		sort(d,d+r);
		for(int i=0;i<r;i++){
			if(m-d[i]>=0){
				m-=d[i];
				ans++;
			}
		}
	if(ans>max_ans)max_ans=ans;
	}
	cout<<max_ans;
	return 0;
} 
