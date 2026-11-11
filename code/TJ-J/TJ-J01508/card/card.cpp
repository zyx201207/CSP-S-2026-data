#include<bits/stdc++.h>

using namespace std;


long long c[5000005],anss[3000005];

int n,m;
int main()
{
	freopen("card.in","r",stdin);

	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		map<int,int> mp;
		vector<int> cards;
		for(int j=i;j<=n;j++){
		//	Ò»¾ÖÄÚ 
			for(int k=0;k<cards.size();k++){
				if(cards[k]==c[j]){
					while(cards[cards.size()-1]!=c[j] && !cards.empty()) {
					//É¾ 
						cards.pop_back();
					}cards.pop_back();
					break;
				}
			}
			cards.push_back(c[j]);
			//2:
			
//			if(mp.find(c[j])!=mp.end()) {
//				while(cards[cards.size()-1]!=c[j]) {
//					//É¾ 
//					cards.pop_back();
//				}
//			}
//			cards.push_back(c[j]);
//			mp[c[j]]++;
			
		}
		for(int i:cards){
			anss[i]++;
		}
		
		//cout<<'\n';
	} 
	for(int i=1;i<=m;i++) cout<<anss[i]<<' ';
	//12
	return 0;
}

