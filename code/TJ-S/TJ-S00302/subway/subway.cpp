#include <bits/stdc++.h>
using namespace std;
int a[500005];
struct node{
	int nam;
	int lenth;	
}b[505][20005];
int t[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
		for(int j=1;j<=t[i];j++){
			cin>>b[i][j].nam>>b[i][j].lenth;
		}
	}
	int ans=0;
	int si;
	int sj;
	for(int i=1;i<=q;i++){
		int q0,q1;
		cin>>q0>>q1;
		if(q0!=0 && q1!=0 && q0!=q1){
			ans=a[q0]+a[q1];
			int t1=1e+7;
			for(int i=1;i<=n;i++){
				while(q0!=q1){
					for(int j=1;j<=t[i];j++){
						if(b[i][j].nam==q0){
							if(b[i][j].lenth==min(t1,b[i][j].lenth)){
								t1=b[i][j].lenth;
								 si=i;
								 sj=j;
							}
					}
				   }	ans+=t1;
				   		q0=b[si][sj].nam;
						   cout<<ans;}
					 
		}
			
	}
	cout<<ans;}
	return 0;
}
