#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int a;
	string a2;
}b[200010];
bool cmp(Node p,Node q){
	return p.a>q.a;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    string sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i].a; 
		int x=b[i].a;
		while(x){
			int c=x%2;
			b[i].a2=b[i].a2+to_string(c);
			x/=2; 
		}
	} 
	sort(b+1,b+n+1,cmp);
	sum=b[1].a2;
    for(int i=2;i<=m;i++){
    	string an="";
    	int l=max(b[i].a2.size(),sum.size());
		for(int k=0;k<l;k++){
			if(b[i].a2[k]=='1'&&sum[k]=='1'){
				an=an+'1';
			} 
			else{
				an=an+'0';
			}
		}
		sum=an;
	}
	int q=1,ans=0;
	for(int i=0;i<sum.size();i++){
		if(sum[i]=='1'){
			ans+=q;
		} 
		q*=2;
	}
	cout<<ans;
	return 0;
}
