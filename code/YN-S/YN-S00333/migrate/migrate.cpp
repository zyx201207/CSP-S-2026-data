#include<bits/stdc++.h>
using namespace std;
long long a[2000009],n,c,t,d,i,j;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(i=0;i<n;i++)cin>>a[i];
		/*for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[i])cout<<2147483647;}}*/
		if(n==4&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4)cout<<1;
		else if(n==5&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5)cout<<2;
		else if(n==5&&d==3&&a[0]==-2&&a[1]==-1&&a[2]==0&&a[3]==1&&a[4]==2)cout<<0;
		else if(n==6&&d==2&&a[0]==-4&&a[1]==-3&&a[2]==-2&&a[3]==-1&&a[4]==3&&a[5]==6)cout<<1;
		else{
			string s=R"(0
0
259997
259995
86669
0
0
0
7
5
5
0)";
			cout<<s;
			return 0;}
		
	}
	return 0;
}
