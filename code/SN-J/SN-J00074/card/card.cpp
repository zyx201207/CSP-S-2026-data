#include<bits/stdc++.h>
using namespace std;
//bool bols[50000][30000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	unsigned long long n=0,m=0;cin>>n>>m;
	vector<unsigned long long>vects(n);
	for(unsigned long long i=0;i<n;i++){
		cin>>vects[i];
	}
	//cout<<"n:"<<n<<"m:"<<m<<'\n';
	vector<vector<bool>>vs(n);
	for(unsigned long long i=1;i<=1;i++){
		//cout<<"i:"<<i<<"\n";
		for(unsigned long long j=0;j<m;j++){
			//cout<<"aaaaaa";
			vs[i].push_back(0);
			
		}
		//cout<<"i:"<<"aaa"<<i<<"\n";
		vector<unsigned long long>now;
		vector<unsigned int>poses(m,0);
		for(unsigned long long j=i-1;j<n;j++){
			unsigned long long nn=vects[j];
			if(vs[i][nn]==0){
				poses[nn]=now.size();
				vs[i][nn]=1;
				now.push_back(nn);
				//cout<<"push"<<nn<<'\n';
				for(unsigned long long j=0;j<now.size();j++){
					cout<<now[j]<<' ';
				}
				//cout<<"end\n";
				
			}
			else{
				unsigned long long pos=poses[nn];
				//cout<<"now.size()-pos:"<<(now.size()-pos==2)<<'\n';
				for(unsigned long long k=0;k<now.size()-pos;k++){
					cout<<"k:"<<k<<'\n';
					vs[i][now.size()-1]=0;
					//cout<<"pop"<<now[now.size()-1]<<'\n';
					now.pop_back();
					for(unsigned long long j=0;j<now.size();j++){
						cout<<now[j]<<' ';
					}
					//cout<<"end\n";
				}
				vs[i][nn]=1;
				poses[nn]=now.size();
				now.push_back(nn);
				for(unsigned long long j=0;j<now.size();j++){
					cout<<now[j]<<' ';
				}
				//cout<<"end\n";
			}
		}
		//cout<<"begin:now:i="<<i<<":";
		for(unsigned long long j=0;j<now.size();j++){
			cout<<now[j]<<' ';
		}
		//cout<<"end\n";
	}
	return 0;
}
