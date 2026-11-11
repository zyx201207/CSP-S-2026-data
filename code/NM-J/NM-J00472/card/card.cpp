#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
/*
	int n,m;
	vector<int> a;
	a[0]=0;
	int b[m]={};
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		int cd=a.size()-1;
		if(cd==0) a.push_back(t);
		if(cd==1){
			if(a[0]!=t) a.push_back(t); 
			
		}
		else{
			int flag=1;
			for(int j=0;j<cd;i++){		
				if(t==a[j]){
					for(int k=0;k<(cd-j);k++)a.pop();
					flag=0;
					break;
				}
			}
			if(flag==1) a.push_back(t);		
		}	
		int cd=a.size();
		for(int j=0;j<cd;j++){
			if(a[i]==i) b[i]++;
			
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[m];
			
	}

*/
	int n,m;
	cin>>n>>m;
	for(int i=m;i>0;i--){
		cout<<i<<' ';
			
	}

	fclose(stdin);
	fclose(stdout);
	
	
	
	return 0;
}
