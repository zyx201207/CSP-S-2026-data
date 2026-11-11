#include<bits/stdc++.h>
using namespace std;
deque<int>de;
int ans[500001],arr[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		bool ishave[500001]={false};
		for(int j=i;j<n;j++){
			if(de.empty()){
			    de.push_back(arr[j]);
				ishave[arr[j]]=true;
			}
			else if(ishave[arr[j]]==false){
				de.push_back(arr[j]);
		    	ishave[arr[j]]=true;
			}
			else if(ishave[arr[j]]==true){
				while(de.back()!=arr[j]){
					ishave[de.back()]=false;
					de.pop_back();
				}
			}
		}
		while(!de.empty()){
			ans[de.front()]++;
			de.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
