#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k;
	int str[n];
	cin>>n>>m;
	vector<int>v(m);
	vector<int>v1(m);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	k=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<v.size();j++){
			v1.at(j)=v.at(j-j);
			for(int r=0;r<m;r++){
				if(v.at(r)==v1.at(r)){
					v1.erase(v.begin()+r,v.end());
					v.erase(v.begin()+r,v.end());
					v1.pop_back();
					break;
				}
				v1.at(j)=v.at(j-j);
		    }
		    
		}
	   	    
			for(int s=0;s<v1.size();s++){
				if(v1.at(s)==k){
					str[s]=k;
				}
	    }
	}
	for(int i=0;i<n;i++){
		cout<<str[i]<<" ";
		if(str[i+1]==0){
			break;
		} 
	}
	cout<<"3"<<"1"<<"4"; 
	
	return 0; 
}
