#include "bits/stdc++.h"
using namespace std;
int n,m;
int arr[500010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	stack<int>s;
	for(int i=0;i<n;i++){
	    cin>>arr[i];	
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(s.size()>0){
				if(arr[j]==s.top()){
				while(s.size()>0){
					s.pop();
				}
			}
			}
			s.push(arr[j]);
			
		}
		
		
		while(s.size()>0){
			ans[s.top()-1]++;
			s.pop();
		}

	}
	for(int i=0;i<m;i++){
	    cout<<ans[i];	
	    if(i!=m-1)cout<<' ';
	}
	
	return 0;
}

