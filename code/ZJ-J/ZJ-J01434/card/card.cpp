#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>ji(m+1,0);
	vector<int>num(n+1,0);
	
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	for(int i=0;i<n;i++){
		vector<int>hand;
		vector<int>jii(m+1,-1);
		for(int ii=i;ii<n;ii++){
			if(jii[num[ii]]!=-1){
				hand.erase(find(hand.begin(),hand.end(),num[ii]),hand.end());
				hand.push_back(num[ii]);
			}else{
				hand.push_back(num[ii]);
				jii[num[ii]]=1;
			}
		}
		for(int i=0;i<hand.size();i++){
			ji[hand[i]]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<ji[i+1]<<" ";
	}
	cout<<endl;
}
