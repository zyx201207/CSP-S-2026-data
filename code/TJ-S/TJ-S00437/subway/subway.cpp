#include<bits/stdc++.h>
using namespace std;
const int N=20005;
int c,n,m,d,q;
int t1[N];
int a[505][N],t[505][N]; 
struct travel{
	int start;
	int end;
}tra;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>t1[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;i<m;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	long long ans=0;
	for(int i=0;i<q;i++){
		cin>>tra.start>>tra.end;
		if(c>=7&&c<=11){
			int h=0;
			ans+=t1[tra.start];
			for(int j=0;j<n;j++){
				if(a[j][0]==tra.start){
					ans+=t[j][0];
					tra.start=a[j][1];
					h=t1[a[j][0]];
					a[j][0]=-1;
					ans+=h;
					a[j][1]=-1;
					
				}
				else if(a[j][1]==tra.start){
					ans+=t[j][1];
					tra.start=a[j][0];
					h=t1[a[j][1]];
					a[j][1]=-1;
					ans+=h;
					a[j][0]=-1;
				}
			}
			ans-=h;
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
