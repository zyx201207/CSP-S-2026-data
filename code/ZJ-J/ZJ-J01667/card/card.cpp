#include<bits/stdc++.h>
using namespace std;
int f[500005];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s+=c;
	}
	for(int i=1;i<=m;i++){
		long long ans=0;
		for(int j=1;j<=n;j++){
			string ss=s;
			for(int k=j-1;k<ss.size();k++){
				cout<<f[ss[k]-'0']<<endl<<ss<<endl;
				if(f[ss[k]-'0']==0)f[ss[k]-'0']=k+1;
				else{
					for(int kk=f[ss[k]-'0']-1;kk<k;kk++)ss[kk]='*';
					f[ss[k]-'0']=k;
				}
			}
			//cout<<ss<<endl;
			for(int k=0;k<ss.size();k++){
				if(ss[k]-'0'==i)ans++;
			}
		}
		cout<<"    "<<ans<<' ';
	}
	return 0;
	
} 
