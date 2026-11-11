#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,d,a[2000005],ans,q[2000005][2],f,e;//weizhi,step
int bfs(int s1,int s2){
	f=e=1,q[1][0]=s1,q[1][1]=0;
	int mi=INT_MAX,sum=0;
	while(f<=e){
		if(q[f][0]==s2){
			if(q[f][1]<mi)mi=q[f][1],sum=1;
			else if(q[f][1]==mi)sum++;
		}
		for(int i=q[f][0]+1;i<=n;i++){
			if(a[i]-a[q[f][0]]>d)break;
			if(q[f][0]>s2||q[f][1]>mi)continue;
			e++,q[e][0]=i,q[e][1]=q[f][1]+1;
		}
		f++;
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(bfs(i,j)==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//15:40-16:00 write a very slow baoli(10pts)
//16:40-17:18 think and write a better code,but wa on yangli 2 and 3,so i still choose 10pts code
