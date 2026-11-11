//20261031-cspj-00547-t4
#include<bits/stdc++.h>
using namespace std;
int cards[300000];
int leftcards[300000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//要写就写的暴力点收到 
	int n,m;
	cin>>n>>m;
	for(int i =0;i<n;i++){
		cin>>cards[i];
	}
	for(int i =0;i<n;i++){
		set<int> s;
		stack<int> s2;
		for(int j =i;j<n;j++){
			//cout<<"==========\n";
			//cout<<cards[j]<<'-'<<s.count(cards[j])<<'\n';
			if(s.count(cards[j])){
				for(int k =0;k<s2.size();k++){
				    if(s2.top()!=cards[j]){
				    	//cout<<"pop"<<s2.top();
				    	s.erase(s2.top());
				    	s2.pop();
					}
				}
			}
			else{
				s.insert(cards[j]);
				s2.push(cards[j]);
				//cout<<"pushed\n";
			}
		}
		//cout<<'\n';
		
		for(int j =1;j<n;j++){
			if(s.count(j)){
				++leftcards[j];
				//cout<<i<<'/';
			}
		}
	}
	
	for(int i =1;i<n;i++){
		if(leftcards[i]>0){
			cout<<leftcards[i]<<' ';
		}
	}
}
