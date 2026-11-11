#include<bits/stdc++.h>
#define LL long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int c,t;
int n,d;
int x[N];
int ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;++i){
			for(int j=i+2;j<=n;++j){
				int s=max(x[i]-x[j],x[j]-x[i]);
				if(s<=d) continue;
				//cout<<"i: "<<i<<" j: "<<j<<" "<<"s: "<<s<<endl;
				int cnt=0;
				for(int w=i+1;w<=j-1;++w){
					int s1=max(x[i]-x[w],x[w]-x[i]);
					int s2=max(x[w]-x[j],x[j]-x[w]);
					//cout<<"w: "<<w<<" s1: "<<s1<<" s2: "<<s2<<endl;
					if(s1<=d&&s2<=d){
						cnt++;
						//cout<<i<<"->"<<w<<"->"<<j<<endl;
					}
				}
				if(cnt==2){
					//cout<<i<<"->"<<w<<"->"<<j<<endl;
					ans++;
				}
			}
		}
		//cout<<"ans: ";
		cout<<ans<<endl;
	}
	return 0;
}
//1:
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

//2:
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
