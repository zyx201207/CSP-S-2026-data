#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		int c,n,m,d,q;
		cin>>c>>n>>m>>d>>q;
		vector<int> sta(m);
		for(int i=0;i<m;i++){
			cin>>sta[i];
		}
		vector<vector<long long>> lie(n,vector<long long>(n,0));
		vector<vector<long long>> ev(n,vector<long long>(m,0));
		vector<vector<int>> ma(m,vector<int>());
		for(int i=0;i<n;i++){
			int num;
			cin>>num;
			for(int j=0;j<num;j++){
				int a;
				long long t;
				cin>>a>>t;
				a--;
				ev[i][a]=t;
				if(!ma[a].empty()){
					for(auto x:ma[a]){
						if(lie[x][i]!=0){
							lie[x][i]=min(ev[x][a]+t,lie[x][i]);
						}else{
							lie[x][i]=ev[x][a]+t;
						}
						lie[i][x]=lie[x][i];
					}
				}
				ma[a].push_back(i);
			}
			
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(lie[i][j]==0) continue;
				for(int x=j+1;x<n;x++){
					if(lie[j][x]==0) continue;
					if(lie[i][x]!=0){
						lie[i][x]=min(lie[i][x],lie[i][j]+lie[j][x]);
					}else{
						lie[i][x]=lie[i][j]+lie[j][x];
					}
					lie[x][i]=lie[i][x];
				}
			}
		}
		
		for(int i=0;i<q;i++){
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			long long  sum=sta[l]+sta[r];
			long long total=LONG_LONG_MAX;
			for(auto x:ma[l]){
				for(auto j:ma[r]){
					if(lie[x][j]+ev[x][l]+ev[j][r]<total){
						total=lie[x][j]+ev[x][l]+ev[j][r];
						
					}
					
				}
			}
			cout<<sum+total<<endl;
		}
		return 0;
}
