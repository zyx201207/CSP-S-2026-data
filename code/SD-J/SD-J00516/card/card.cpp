#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 500003
int a[maxn],b,c,d,i,j,k,m,n,now[maxn],ans[maxn],sum,tot,cnt,l,r,p,x,y,t,dis[maxn];
string s1,s2,s3,s4;
char s[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		//fill(now+1,now+1+n,0);
		int ve[10000];
		int tot=0;
		for(j=i;j<=n;j++){
			int ok=0;
			for(k=1;k<=n;k++){
				if(ve[k]==a[j]){
					ok=1;
					continue;
				}
				if(ok==1)ve[k]=0,tot--;
			}
			if(ok==0)ve[++tot]=a[j];
			//cout<<ve[i];	
		}
		/*for(k=1;k<=n;k++){
			cout<<ve[k]<<' ';
			ans[ve[k]]++;
		}
		cout<<"\n";*/
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
