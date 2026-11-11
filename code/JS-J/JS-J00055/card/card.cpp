#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> card;
vector<int> now,res;
vector<bool> num;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	card.resize(n);
	for(int i=0;i<n;++i) cin>>card[i];
	num.assign(m+1,false);
	res.resize(m+1);
	for(int i=0;i<n;++i){
		now.clear();
		for(int j=0;j<m+1;++j) num[j]=false;
		for(int j=i+1;j<=n;++j){
			int now_card=card[j-1];
			if(!num[now_card]){
				now.push_back(now_card);
				num[now_card]=true;
			}
			else{
				while(now[(int)now.size()-1]!=num[now_card]){
					num[now[(int)now.size()-1]]=false;
					now.pop_back();
				}
			}
		}
		for(int j=0;j<(int)now.size();++j){
			res[now[j]]++;
		}
	}
	for(int i=1;i<=m;++i)
		cout<<res[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
